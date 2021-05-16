
#include "particle.h"

// ToDo: define memory managment here

class MemoryBlockManager
{
    typedef unsigned char uchar;

    uint32_t _num_blocks;
    uint32_t _num_free_blocks;
    uint32_t _num_initialized_blocks;
    uint32_t _block_size;
    uchar *_memory_start;
    uchar *_next;

public:
    MemoryBlockManager(uint32_t block_size, uint32_t num_blocks)
        : _num_blocks(num_blocks), _num_free_blocks(num_blocks), _num_initialized_blocks(0), _block_size(block_size)

    {
        _memory_start = new uchar[_num_blocks * _block_size];
        _next = _memory_start;
    }

    ~MemoryBlockManager()
    {
        delete[] _memory_start;
        _memory_start = nullptr;
    }

    void *alloc()
    {
        void *result = nullptr;

        // make shure all blocks are initialized
        if (_num_initialized_blocks < _num_blocks)
        {
            uint32_t *p = (uint32_t *)address_from_index(_num_initialized_blocks);
            *p = _num_initialized_blocks + 1;
            _num_initialized_blocks++;
        }

        // if we have a free blocks return a pointer to it
        if (_num_free_blocks > 0)
        {
            result = (void *)_next;
            _num_free_blocks--;

            if (_num_free_blocks)
            {
                _next = address_from_index(*((uint32_t *)_next));
            }
            else
            {
                _next = nullptr;
            }
        }

        return result;
    };

    void dealloc(void *p)
    {
        if (_next != nullptr)
        {
            (*(uint32_t *)p) = index_from_address(_next);
            _next = (uchar *)p;
        }
        else
        {
            (*(uint32_t *)p) = _num_blocks;
            _next = (uchar *)p;
        }

        _num_free_blocks++;
    };

private:
    uchar *address_from_index(uint32_t i) const
    {
        return _memory_start + (i * _block_size);
    }

    uint32_t index_from_address(const uchar *p)
    {
        return (((uint32_t)(p - _memory_start)) / _block_size);
    }

}

void *
Particle::operator new(std::size_t size)
{
    return m.alloc();
}

void Particle::operator delete(void *p)
{
    m.dealloc(p);
}
}

MemoryBlockManager Particle::m{sizeof(Particle), 100000};

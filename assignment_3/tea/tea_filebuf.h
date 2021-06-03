
#pragma once

#include <array>
#include <cstdint>
#include <cstring>
#include <fstream>


const auto g_tea_key = std::array<std::uint32_t, 4>{{ 0xA04D1BF9u, 0x082D1191u, 0xc2B959D7u, 0x1E35969Cu }};


// Implement your TEA stream buffer here
class tea_streambuf: public std::streambuf
{
public:
    int underflow() override;
    explicit tea_streambuf(std::streambuf *buf);
};

class tea_istream: public std::istream
{
public:
    tea_istream(std::istream &stream) :
            std::istream(new tea_streambuf(stream.rdbuf())) {}

    ~tea_istream() override
    {
        delete rdbuf();
    }
};
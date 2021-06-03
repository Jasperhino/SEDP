#include "tea_filebuf.h"

void decrypt(std::array<uint32_t, 2> v, const std::array<uint32_t, 4> k) {
    uint32_t v0 = v[0], v1 = v[1], sum = 0xC6EF3720, i;  /* set up; sum is (delta << 5) & 0xFFFFFFFF */
    uint32_t delta = 0x9E3779B9;                     /* a key schedule constant */
    uint32_t k0 = k[0], k1 = k[1], k2 = k[2], k3 = k[3];   /* cache key */
    for (i = 0; i < 32; i++) {                         /* basic cycle start */
        v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
        v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
        sum -= delta;
    }                                              /* end cycle */
    v[0] = v0;
    v[1] = v1;
}

int tea_streambuf::underflow() {
    auto s = new std::array<uint32_t , 2>;
    this->sgetn((char *) s, 8);
    decrypt(*s, g_tea_key);

    return this->gptr() == this->egptr()
           ? std::char_traits<char>::eof()
           : std::char_traits<char>::to_int_type(*this->gptr());
}

tea_streambuf::tea_streambuf(std::streambuf *buf): buf(buf) {};

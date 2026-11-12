#include "hash.hpp"
#include <cstdint>

std::uint32_t table::hasher(const char* key) const {
    unsigned int hash = 0x811c9dc5u;
    while (*key) {
        hash ^= static_cast<unsigned char>(*key);
        hash *= 0x01000193u;
        ++key;
    }
    return hash;
}

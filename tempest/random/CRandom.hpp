#ifndef TEMPEST_RANDOM_C_RANDOM_HPP
#define TEMPEST_RANDOM_C_RANDOM_HPP

#include "tempest/random/CRndSeed.hpp"
#include <cstdint>

extern const uint32_t gnoise32[];

class CRandom {
    public:
        // Static functions
        static uint32_t uint32(CRndSeed& seed);
};

#endif

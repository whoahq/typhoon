#ifndef TEMPEST_RANDOM_C_RND_SEED_HPP
#define TEMPEST_RANDOM_C_RND_SEED_HPP

#include <cstdint>

class CRndSeed {
    friend class CRandom;

    public:
        // Public member functions
        CRndSeed(uint32_t seed);
        void SetSeed(uint32_t seed);

    protected:
        // Protected member variables
        uint32_t rndacc;
        uint32_t rndvls;
};

#endif

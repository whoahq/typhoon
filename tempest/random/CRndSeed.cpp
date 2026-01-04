#include "tempest/random/CRndSeed.hpp"

CRndSeed::CRndSeed(uint32_t seed) {
    this->SetSeed(seed);
}

void CRndSeed::SetSeed(uint32_t seed) {
    this->rndacc = seed;
    this->rndvls = (4 * (seed % 0x3D)) | ((seed % 0x3B) << 10) | ((seed % 0x35) << 18) | ((seed % 0x2F) << 26);
}

#include "tempest/vector/CImVector.hpp"
#include "tempest/Math.hpp"

uint32_t CImVector::MakeARGB(uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
    return a << 24 | r << 16 | g << 8 | b;
}

bool CImVector::operator==(const CImVector& color) {
    return this->value == color.value;
}

void CImVector::Set(float a, float r, float g, float b) {
    uint8_t a_ = CMath::fuint_n(a * 255.0f);
    uint8_t r_ = CMath::fuint_n(r * 255.0f);
    uint8_t g_ = CMath::fuint_n(g * 255.0f);
    uint8_t b_ = CMath::fuint_n(b * 255.0f);

    this->value = CImVector::MakeARGB(a_, r_, g_, b_);
}

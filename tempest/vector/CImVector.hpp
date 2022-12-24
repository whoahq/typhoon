#ifndef TEMPEST_VECTOR_C_IMVECTOR_HPP
#define TEMPEST_VECTOR_C_IMVECTOR_HPP

#include <cstdint>

class CImVector {
    public:
    // Static functions
    static uint32_t MakeARGB(uint8_t a, uint8_t r, uint8_t g, uint8_t b);

    // Member variables
    union {
        struct {
            uint8_t b;
            uint8_t g;
            uint8_t r;
            uint8_t a;
        };

        uint32_t value;
    };

    bool operator==(const CImVector& color);
    void Set(float a, float r, float g, float b);
};

#endif

#ifndef TEMPEST_VECTOR_C_3IVECTOR_HPP
#define TEMPEST_VECTOR_C_3IVECTOR_HPP

#include <cstdint>

class C3iVector {
    public:
    // Member variables
    int32_t x;
    int32_t y;
    int32_t z;

    // Member functions
    C3iVector()
        : C3iVector(0) {};
    C3iVector(int32_t a)
        : C3iVector(a, a, a) {};
    C3iVector(const C3iVector& v)
        : C3iVector(v.x, v.y, v.z) {};
    C3iVector(int32_t x, int32_t y, int32_t z)
        : x(x)
        , y(y)
        , z(z) {};
};

#endif

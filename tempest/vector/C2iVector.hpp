#ifndef TEMPEST_VECTOR_C_2IVECTOR_HPP
#define TEMPEST_VECTOR_C_2IVECTOR_HPP

#include <cstdint>

class C2iVector {
    public:
    // Member variables
    int32_t x;
    int32_t y;

    // Member functions
    C2iVector()
        : C2iVector(0) {};
    C2iVector(int32_t a)
        : C2iVector(a, a) {};
    C2iVector(const C2iVector& v)
        : C2iVector(v.x, v.y) {};
    C2iVector(int32_t x, int32_t y)
        : x(x)
        , y(y) {};
};

#endif

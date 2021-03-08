#ifndef TEMPEST_MATRIX_C_34MATRIX_HPP
#define TEMPEST_MATRIX_C_34MATRIX_HPP

#include "tempest/vector/C3Vector.hpp"

class C34Matrix {
    public:
    // Member variables
    float a0 = 1.0f;
    float a1 = 0.0f;
    float a2 = 0.0f;
    float b0 = 0.0f;
    float b1 = 1.0f;
    float b2 = 0.0f;
    float c0 = 0.0f;
    float c1 = 0.0f;
    float c2 = 1.0f;
    float d0 = 0.0f;
    float d1 = 0.0f;
    float d2 = 0.0f;

    // Member functions
    C34Matrix() = default;
    C34Matrix(float a0, float a1, float a2, float b0, float b1, float b2, float c0, float c1, float c2, float d0, float d1, float d2)
        : a0(a0)
        , a1(a1)
        , a2(a2)
        , b0(b0)
        , b1(b1)
        , b2(b2)
        , c0(c0)
        , c1(c1)
        , c2(c2)
        , d0(d0)
        , d1(d1)
        , d2(d2) {};

    void Translate(const C3Vector& move);
    C34Matrix& operator+=(const C34Matrix& a);
    C34Matrix& operator-=(const C34Matrix& a);
};

C34Matrix operator+(const C34Matrix& l, const C34Matrix& r);

C34Matrix operator-(const C34Matrix& l, const C34Matrix& r);

C34Matrix operator*(const C34Matrix& l, const C34Matrix& r);

C34Matrix operator*(const C34Matrix& l, const float& a);

C3Vector operator*(const C34Matrix& l, const C3Vector& r);

#endif

#ifndef TEMPEST_MATRIX_C_33MATRIX_HPP
#define TEMPEST_MATRIX_C_33MATRIX_HPP

#include "tempest/vector/C3Vector.hpp"

class C33Matrix {
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

    // Member functions
    C33Matrix() = default;
    C33Matrix(float a0, float a1, float a2, float b0, float b1, float b2, float c0, float c1, float c2)
        : a0(a0)
        , a1(a1)
        , a2(a2)
        , b0(b0)
        , b1(b1)
        , b2(b2)
        , c0(c0)
        , c1(c1)
        , c2(c2) {};
    C33Matrix Adjoint() const;
    float Determinant() const;
    C33Matrix Inverse(float det) const;
};

C33Matrix operator*(const C33Matrix& l, float a);

C33Matrix operator/(const C33Matrix& l, float a);

C33Matrix operator*(const C33Matrix& l, const C33Matrix& r);

C3Vector operator*(const C33Matrix& l, const C3Vector& r);

#endif

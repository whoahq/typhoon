#ifndef TEMPEST_VECTOR_C_3VECTOR_HPP
#define TEMPEST_VECTOR_C_3VECTOR_HPP

#include "tempest/vector/CImVector.hpp"

class C44Matrix;

class C3Vector {
    public:
    // Static functions
    static C3Vector Cross(const C3Vector& l, const C3Vector& r);

    // Member variables
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    // Member functions
    C3Vector() = default;
    C3Vector(float x, float y, float z)
        : x(x)
        , y(y)
        , z(z) {};
    C3Vector(const CImVector& color)
        : x(color.r / 255.0f)
        , y(color.g / 255.0f)
        , z(color.b / 255.0f) {};
    C3Vector operator-() const;
    C3Vector& operator*=(float a);
    float Mag() const;
    void Normalize();
    float SquaredMag() const;
};

C3Vector operator+(const C3Vector& l, const C3Vector& r);

C3Vector operator*(const C3Vector& l, const C44Matrix& r);

bool operator!=(const C3Vector& l, const C3Vector& r);

#endif

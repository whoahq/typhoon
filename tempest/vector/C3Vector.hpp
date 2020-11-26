#ifndef TEMPEST_VECTOR_C_3VECTOR_HPP
#define TEMPEST_VECTOR_C_3VECTOR_HPP

class C3Vector {
    public:
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
    C3Vector& operator*=(float a);
    float Mag() const;
    void Normalize();
    float SquaredMag() const;
};

C3Vector operator+(const C3Vector& l, const C3Vector& r);

bool operator!=(const C3Vector& l, const C3Vector& r);

#endif

#ifndef TEMPEST_VECTOR_C_4VECTOR_HPP
#define TEMPEST_VECTOR_C_4VECTOR_HPP

class C4Vector {
    public:
    // Member variables
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 0.0f;

    // Member functions
    C4Vector() = default;
    C4Vector(float x, float y, float z, float w)
        : x(x)
        , y(y)
        , z(z)
        , w(w) {};
};

#endif

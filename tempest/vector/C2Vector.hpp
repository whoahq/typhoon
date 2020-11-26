#ifndef TEMPEST_VECTOR_C_2VECTOR_HPP
#define TEMPEST_VECTOR_C_2VECTOR_HPP

class C2Vector {
    public:
    // Member variables
    float x = 0.0f;
    float y = 0.0f;

    // Member functions
    C2Vector() = default;
    C2Vector(float x, float y)
        : x(x)
        , y(y) {};
};

#endif

#ifndef TEMPEST_QUATERNION_C_4QUATERNION_HPP
#define TEMPEST_QUATERNION_C_4QUATERNION_HPP

class C4Quaternion {
    public:
    // Static functions
    static C4Quaternion Nlerp(float ratio, const C4Quaternion& q1, const C4Quaternion& q2);

    // Member variables
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 1.0f;

    // Member functions
    C4Quaternion() = default;
    C4Quaternion(float x, float y, float z, float w)
        : x(x)
        , y(y)
        , z(z)
        , w(w) {};
};

#endif

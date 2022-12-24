#include "tempest/quaternion/C4Quaternion.hpp"

C4Quaternion C4Quaternion::Nlerp(float ratio, const C4Quaternion& q1, const C4Quaternion& q2) {
    float x = (q2.x - q1.x) * ratio + q1.x;
    float y = (q2.y - q1.y) * ratio + q1.y;
    float z = (q2.z - q1.z) * ratio + q1.z;
    float w = (q2.w - q1.w) * ratio + q1.w;

    float m = x * x + y * y + z * z + w * w;
    float v9 = ((m - 0.95906597) * -0.532516) + 1.021435;

    if (m <= 0.91521198) {
        v9 *= (((v9 * v9 * m) - 0.95906597) * -0.532516) + 1.021435;

        if (m <= 0.6521197) {
            v9 *= (((v9 * v9 * m) - 0.95906597) * -0.532516) + 1.021435;
        }
    }

    x *= v9;
    y *= v9;
    z *= v9;
    w *= v9;

    return { x, y, z, w };
}

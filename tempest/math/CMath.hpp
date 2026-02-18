#ifndef TEMPEST_MATH_C_MATH_HPP
#define TEMPEST_MATH_C_MATH_HPP

#include <cmath>
#include <cstdint>
#include <storm/Error.hpp>

class CMath {
    public:
    // Static variables
    static const float PI;
    static const float TWO_PI;
    static const float OO_TWO_PI;
    static const float EPSILON;
    static const float DEG2RAD;

    // Static functions
    static float cos(float x) {
        return std::cos(x);
    }

    static float fabs(float x) {
        return std::fabs(x);
    }

    static bool fequal(float a, float b) {
        return CMath::fequalz(a, b, EPSILON);
    }

    static bool fequalz(float a, float b, float z) {
        return z > CMath::fabs(a - b);
    }

    static int32_t fint(float n) {
        return static_cast<int32_t>(n);
    }

    static int32_t fint_n(float n) {
        return n <= 0.0f ? static_cast<int32_t>(n - 0.5f) : static_cast<int32_t>(n + 0.5f);
    }

    static bool fnotequal(float a, float b) {
        return !CMath::fequal(a, b);
    }

    static bool fnotequalz(float a, float b, float z) {
        return !CMath::fequalz(a, b, z);
    }

    static uint32_t fuint(float n) {
        return static_cast<uint32_t>(n);
    }

    static uint32_t fuint_n(float n) {
        return static_cast<uint32_t>(n + 0.5f);
    }

    static uint32_t fuint_pi(float n) {
        return static_cast<uint32_t>(n + 0.99994999);
    }

    static float hypotinv(float x, float y) {
        float s = (x * x) + (y * y);
        STORM_ASSERT(s >= 0.0f);

        return CMath::sqrtinv(s);
    }

    static uint32_t mulhwu(uint32_t x, uint32_t y) {
        return (y * static_cast<uint64_t>(x)) >> 32;
    }

    static void normalize(float& x, float& y) {
        auto hi = CMath::hypotinv(x, y);

        x *= hi;
        y *= hi;
    }

    static uint32_t rotl3(uint32_t v) {
        return (v << 3) | (v >> 29);
    }

    static uint32_t rotl2(uint32_t v) {
        return (v << 2) | (v >> 30);
    }

    static uint32_t rotl1(uint32_t v) {
        return (v << 1) | (v >> 31);
    }

    static float sin(float x) {
        return std::sin(x);
    }

    static float sqrt(float x) {
        STORM_ASSERT(x >= 0.0f);
        return ::sqrt(x);
    }

    static float sqrtinv(float x) {
        return 1.0f / ::sqrt(x);
    }
};

#endif

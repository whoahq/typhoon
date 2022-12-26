#ifndef TEMPEST_MATH_C_MATH_HPP
#define TEMPEST_MATH_C_MATH_HPP

#include <cmath>
#include <cstdint>
#include <storm/Error.hpp>

class CMath {
    public:
    // Static variables
    static constexpr float PI = 3.1415927f;
    static constexpr float TWO_PI = 6.2831855f;
    static constexpr float OO_TWO_PI = 1.0f / TWO_PI;

    // Static functions
    static int32_t fint(float n) {
        return static_cast<int32_t>(n);
    }

    static int32_t fint_n(float n) {
        return n <= 0.0f ? static_cast<int32_t>(n - 0.5f) : static_cast<int32_t>(n + 0.5f);
    }

    static uint32_t fuint(float n) {
        return static_cast<uint32_t>(n);
    }

    static uint32_t fuint_n(float n) {
        return static_cast<uint32_t>(n + 0.5f);
    }

    static float sqrt(float x) {
        STORM_ASSERT(x >= 0.0f);
        return ::sqrt(x);
    }
};

#endif

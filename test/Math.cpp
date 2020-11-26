#include "tempest/Math.hpp"
#include "test/Test.hpp"

TEST_CASE("CMath::fuint", "[math]") {
    SECTION("converts 1.0f to 1u") {
        auto result = CMath::fuint(1.0f);
        REQUIRE(result == 1u);
    }

    SECTION("converts 1.5f to 1u") {
        auto result = CMath::fuint(1.5f);
        REQUIRE(result == 1u);
    }

    SECTION("converts 1.999f to 1u") {
        auto result = CMath::fuint(1.999f);
        REQUIRE(result == 1u);
    }

    SECTION("converts 0.0f to 0u") {
        auto result = CMath::fuint(0.0f);
        REQUIRE(result == 0u);
    }
}

TEST_CASE("CMath::fuint_n", "[math]") {
    SECTION("converts 1.0f to 1u") {
        auto result = CMath::fuint_n(1.0f);
        REQUIRE(result == 1u);
    }

    SECTION("converts 1.5f to 2u") {
        auto result = CMath::fuint_n(1.5f);
        REQUIRE(result == 2u);
    }

    SECTION("converts 1.999f to 2u") {
        auto result = CMath::fuint_n(1.999f);
        REQUIRE(result == 2u);
    }

    SECTION("converts 0.0f to 0u") {
        auto result = CMath::fuint_n(0.0f);
        REQUIRE(result == 0u);
    }
}

TEST_CASE("CMath::sqrt", "[math]") {
    SECTION("returns the square root of 4.0f") {
        auto result = CMath::sqrt(4.0f);
        REQUIRE(result == 2.0f);
    }

    SECTION("returns the square root of 0.0f") {
        auto result = CMath::sqrt(0.0f);
        REQUIRE(result == 0.0f);
    }
}

#include "tempest/Vector.hpp"
#include "test/Test.hpp"

TEST_CASE("C3Vector", "[vector]") {
    SECTION("constructs with default constructor") {
        C3Vector vector;
        REQUIRE(vector.x == 0.0f);
        REQUIRE(vector.y == 0.0f);
        REQUIRE(vector.z == 0.0f);
    }

    SECTION("constructs with xyz constructor") {
        auto vector = C3Vector(1.0f, 2.0f, 3.0f);
        REQUIRE(vector.x == 1.0f);
        REQUIRE(vector.y == 2.0f);
        REQUIRE(vector.z == 3.0f);
    }
}

TEST_CASE("C3Vector::operator*=", "[vector]") {
    SECTION("multiplies by 2.0f") {
        auto vector = C3Vector(1.0f, 2.0f, 3.0f);
        vector *= 2.0f;
        REQUIRE(vector.x == 2.0f);
        REQUIRE(vector.y == 4.0f);
        REQUIRE(vector.z == 6.0f);
    }

    SECTION("multiplies by -2.0f") {
        auto vector = C3Vector(1.0f, 2.0f, 3.0f);
        vector *= -2.0f;
        REQUIRE(vector.x == -2.0f);
        REQUIRE(vector.y == -4.0f);
        REQUIRE(vector.z == -6.0f);
    }

    SECTION("multiplies by 0.0f") {
        auto vector = C3Vector(1.0f, 2.0f, 3.0f);
        vector *= 0.0f;
        REQUIRE(vector.x == 0.0f);
        REQUIRE(vector.y == 0.0f);
        REQUIRE(vector.z == 0.0f);
    }
}

TEST_CASE("C3Vector::SquaredMag", "[vector]") {
    SECTION("calculates squared mag") {
        auto vector = C3Vector(1.0f, 2.0f, 3.0f);
        REQUIRE(vector.SquaredMag() == 14.0f);
    }

    SECTION("calculates squared mag of C3Vector(0.0f, 0.0f, 0.0f)") {
        auto vector = C3Vector(0.0f, 0.0f, 0.0f);
        REQUIRE(vector.SquaredMag() == 0.0f);
    }

    SECTION("calculates squared mag of C3Vector(1.0f, 1.0f, 1.0f)") {
        auto vector = C3Vector(1.0f, 1.0f, 1.0f);
        REQUIRE(vector.SquaredMag() == 3.0f);
    }

    SECTION("calculates squared mag of C3Vector(-1.0f, -1.0f, -1.0f)") {
        auto vector = C3Vector(-1.0f, -1.0f, -1.0f);
        REQUIRE(vector.SquaredMag() == 3.0f);
    }
}

#include "tempest/Vector.hpp"
#include "test/Test.hpp"

TEST_CASE("C2Vector", "[vector]") {
    SECTION("constructs with default constructor") {
        C2Vector vector;
        CHECK(vector.x == 0.0f);
        CHECK(vector.y == 0.0f);
    }

    SECTION("constructs with xy constructor") {
        auto vector = C2Vector(1.0f, 2.0f);
        CHECK(vector.x == 1.0f);
        CHECK(vector.y == 2.0f);
    }
}

TEST_CASE("C2Vector::operator==", "[vector]") {
    SECTION("returns true when compared to identical vector") {
        auto vector1 = C2Vector(1.0f, 2.0f);
        auto vector2 = C2Vector(1.0f, 2.0f);
        auto identical = vector1 == vector2;
        REQUIRE(identical);
    }

    SECTION("returns false when compared to different vector") {
        auto vector1 = C2Vector(2.0f, 1.0f);
        auto vector2 = C2Vector(1.0f, 2.0f);
        auto identical = vector1 == vector2;
        REQUIRE(!identical);
    }
}

TEST_CASE("C3Vector", "[vector]") {
    SECTION("constructs with default constructor") {
        C3Vector vector;
        CHECK(vector.x == 0.0f);
        CHECK(vector.y == 0.0f);
        CHECK(vector.z == 0.0f);
    }

    SECTION("constructs with xyz constructor") {
        auto vector = C3Vector(1.0f, 2.0f, 3.0f);
        CHECK(vector.x == 1.0f);
        CHECK(vector.y == 2.0f);
        CHECK(vector.z == 3.0f);
    }
}

TEST_CASE("C3Vector::operator*=", "[vector]") {
    SECTION("multiplies by 2.0f") {
        auto vector = C3Vector(1.0f, 2.0f, 3.0f);
        vector *= 2.0f;
        CHECK(vector.x == 2.0f);
        CHECK(vector.y == 4.0f);
        CHECK(vector.z == 6.0f);
    }

    SECTION("multiplies by -2.0f") {
        auto vector = C3Vector(1.0f, 2.0f, 3.0f);
        vector *= -2.0f;
        CHECK(vector.x == -2.0f);
        CHECK(vector.y == -4.0f);
        CHECK(vector.z == -6.0f);
    }

    SECTION("multiplies by 0.0f") {
        auto vector = C3Vector(1.0f, 2.0f, 3.0f);
        vector *= 0.0f;
        CHECK(vector.x == 0.0f);
        CHECK(vector.y == 0.0f);
        CHECK(vector.z == 0.0f);
    }
}

TEST_CASE("C3Vector::Mag", "[vector]") {
    SECTION("calculates mag") {
        auto vector = C3Vector(4.0f, 16.0f, 32.0f);
        REQUIRE(vector.Mag() == 36.0f);
    }

    SECTION("calculates mag of C3Vector(0.0f, 0.0f, 0.0f)") {
        auto vector = C3Vector(0.0f, 0.0f, 0.0f);
        REQUIRE(vector.Mag() == 0.0f);
    }

    SECTION("calculates mag of C3Vector(-4.0f, -16.0f, -32.0f)") {
        auto vector = C3Vector(-4.0f, -16.0f, -32.0f);
        REQUIRE(vector.Mag() == 36.0f);
    }
}

TEST_CASE("C3Vector::Normalize", "[vector]") {
    SECTION("normalizes C3Vector(1.0f, 1.0f, 1.0f)") {
        auto vector = C3Vector(1.0f, 1.0f, 1.0f);
        vector.Normalize();
        CHECK(vector.x == Approx(0.57735f));
        CHECK(vector.y == Approx(0.57735f));
        CHECK(vector.z == Approx(0.57735f));
    }

    SECTION("normalizes C3Vector(4.0f, 16.0f, 32.0f)") {
        auto vector = C3Vector(4.0f, 16.0f, 32.0f);
        vector.Normalize();
        CHECK(vector.x == Approx(0.11111f));
        CHECK(vector.y == Approx(0.44444f));
        CHECK(vector.z == Approx(0.88888f));
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

TEST_CASE("C3Vector global operators", "[vector]") {
    SECTION("C3Vector + C3Vector") {
        auto vector1 = C3Vector(1.0f, 2.0f, 3.0f);
        auto vector2 = C3Vector(4.0f, 5.0f, 6.0f);
        auto vector3 = vector1 + vector2;
        CHECK(vector3.x == 5.0f);
        CHECK(vector3.y == 7.0f);
        CHECK(vector3.z == 9.0f);
    }

    SECTION("C3Vector != C3Vector") {
        auto vector1 = C3Vector(1.0f, 2.0f, 3.0f);
        auto vector2 = C3Vector(4.0f, 5.0f, 6.0f);
        REQUIRE(vector1 != vector2);
    }
}

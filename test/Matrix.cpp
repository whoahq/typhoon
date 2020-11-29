#include "tempest/Matrix.hpp"
#include "test/Test.hpp"

TEST_CASE("C44Matrix", "[matrix]") {
    SECTION("constructs with default constructor") {
        C44Matrix matrix;
        REQUIRE(matrix.a0 == 1.0f);
        REQUIRE(matrix.a1 == 0.0f);
        REQUIRE(matrix.a2 == 0.0f);
        REQUIRE(matrix.a3 == 0.0f);
        REQUIRE(matrix.b0 == 0.0f);
        REQUIRE(matrix.b1 == 1.0f);
        REQUIRE(matrix.b2 == 0.0f);
        REQUIRE(matrix.b3 == 0.0f);
        REQUIRE(matrix.c0 == 0.0f);
        REQUIRE(matrix.c1 == 0.0f);
        REQUIRE(matrix.c2 == 1.0f);
        REQUIRE(matrix.c3 == 0.0f);
        REQUIRE(matrix.d0 == 0.0f);
        REQUIRE(matrix.d1 == 0.0f);
        REQUIRE(matrix.d2 == 0.0f);
        REQUIRE(matrix.d3 == 1.0f);
    }

    SECTION("constructs with element constructor") {
        auto matrix = C44Matrix(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
        REQUIRE(matrix.a0 == 1.0f);
        REQUIRE(matrix.a1 == 2.0f);
        REQUIRE(matrix.a2 == 3.0f);
        REQUIRE(matrix.a3 == 4.0f);
        REQUIRE(matrix.b0 == 5.0f);
        REQUIRE(matrix.b1 == 6.0f);
        REQUIRE(matrix.b2 == 7.0f);
        REQUIRE(matrix.b3 == 8.0f);
        REQUIRE(matrix.c0 == 9.0f);
        REQUIRE(matrix.c1 == 10.0f);
        REQUIRE(matrix.c2 == 11.0f);
        REQUIRE(matrix.c3 == 12.0f);
        REQUIRE(matrix.d0 == 13.0f);
        REQUIRE(matrix.d1 == 14.0f);
        REQUIRE(matrix.d2 == 15.0f);
        REQUIRE(matrix.d3 == 16.0f);
    }
}

TEST_CASE("C44Matrix::Adjoint", "[matrix]") {
    SECTION("returns adjoint of identity matrix") {
        C44Matrix matrix;
        auto adjoint = matrix.Adjoint();
        CHECK(adjoint.a0 == 1.0f);
        CHECK(adjoint.a1 == 0.0f);
        CHECK(adjoint.a2 == 0.0f);
        CHECK(adjoint.a3 == 0.0f);
        CHECK(adjoint.b0 == 0.0f);
        CHECK(adjoint.b1 == 1.0f);
        CHECK(adjoint.b2 == 0.0f);
        CHECK(adjoint.b3 == 0.0f);
        CHECK(adjoint.c0 == 0.0f);
        CHECK(adjoint.c1 == 0.0f);
        CHECK(adjoint.c2 == 1.0f);
        CHECK(adjoint.c3 == 0.0f);
        CHECK(adjoint.d0 == 0.0f);
        CHECK(adjoint.d1 == 0.0f);
        CHECK(adjoint.d2 == 0.0f);
        CHECK(adjoint.d3 == 1.0f);
    }

    SECTION("returns adjoint of non-identity matrix") {
        auto matrix = C44Matrix(-1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
        auto adjoint = matrix.Adjoint();
        CHECK(adjoint.a0 == 0.0f);
        CHECK(adjoint.a1 == 0.0f);
        CHECK(adjoint.a2 == 0.0f);
        CHECK(adjoint.a3 == 0.0f);
        CHECK(adjoint.b0 == 0.0f);
        CHECK(adjoint.b1 == 8.0f);
        CHECK(adjoint.b2 == -16.0f);
        CHECK(adjoint.b3 == 8.0f);
        CHECK(adjoint.c0 == 0.0f);
        CHECK(adjoint.c1 == -16.0f);
        CHECK(adjoint.c2 == 32.0f);
        CHECK(adjoint.c3 == -16.0f);
        CHECK(adjoint.d0 == 0.0f);
        CHECK(adjoint.d1 == 8.0f);
        CHECK(adjoint.d2 == -16.0f);
        CHECK(adjoint.d3 == 8.0f);
    }

    SECTION("does not modify self") {
        auto matrix = C44Matrix(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
        auto adjoint = matrix.Adjoint();
        CHECK(matrix.a0 == 1.0f);
        CHECK(matrix.a1 == 2.0f);
        CHECK(matrix.a2 == 3.0f);
        CHECK(matrix.a3 == 4.0f);
        CHECK(matrix.b0 == 5.0f);
        CHECK(matrix.b1 == 6.0f);
        CHECK(matrix.b2 == 7.0f);
        CHECK(matrix.b3 == 8.0f);
        CHECK(matrix.c0 == 9.0f);
        CHECK(matrix.c1 == 10.0f);
        CHECK(matrix.c2 == 11.0f);
        CHECK(matrix.c3 == 12.0f);
        CHECK(matrix.d0 == 13.0f);
        CHECK(matrix.d1 == 14.0f);
        CHECK(matrix.d2 == 15.0f);
        CHECK(matrix.d3 == 16.0f);
    }
}

TEST_CASE("C44Matrix::Determinant", "[matrix]") {
    SECTION("returns determinant of identity matrix") {
        C44Matrix matrix;
        auto determinant = matrix.Determinant();
        REQUIRE(determinant == 1.0f);
    }

    SECTION("returns determinant of zero matrix") {
        auto matrix = C44Matrix(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        auto determinant = matrix.Determinant();
        REQUIRE(determinant == 0.0f);
    }

    SECTION("returns determinant of non-identity matrix") {
        auto matrix = C44Matrix(-1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, -11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
        auto determinant = matrix.Determinant();
        REQUIRE(determinant == -704.0f);
    }
}

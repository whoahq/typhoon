#include "tempest/Matrix.hpp"
#include "test/Test.hpp"

TEST_CASE("C44Matrix::RotationAroundZ", "[matrix]") {
    SECTION("returns rotation matrix for 0 degree angle") {
        auto rotation = C44Matrix::RotationAroundZ(0.0f);
        CHECK(rotation.a0 == 1.0f);
        CHECK(rotation.a1 == 0.0f);
        CHECK(rotation.a2 == 0.0f);
        CHECK(rotation.a3 == 0.0f);
        CHECK(rotation.b0 == 0.0f);
        CHECK(rotation.b1 == 1.0f);
        CHECK(rotation.b2 == 0.0f);
        CHECK(rotation.b3 == 0.0f);
        CHECK(rotation.c0 == 0.0f);
        CHECK(rotation.c1 == 0.0f);
        CHECK(rotation.c2 == 1.0f);
        CHECK(rotation.c3 == 0.0f);
        CHECK(rotation.d0 == 0.0f);
        CHECK(rotation.d1 == 0.0f);
        CHECK(rotation.d2 == 0.0f);
        CHECK(rotation.d3 == 1.0f);
    }

    SECTION("returns rotation matrix for 180 degree angle") {
        auto rotation = C44Matrix::RotationAroundZ(3.1415927f);
        CHECK(rotation.a0 == Approx(-1.0f).margin(0.0000001f));
        CHECK(rotation.a1 == Approx(0.0f).margin(0.0000001f));
        CHECK(rotation.a2 == 0.0f);
        CHECK(rotation.a3 == 0.0f);
        CHECK(rotation.b0 == Approx(0.0f).margin(0.0000001f));
        CHECK(rotation.b1 == Approx(-1.0f).margin(0.0000001f));
        CHECK(rotation.b2 == 0.0f);
        CHECK(rotation.b3 == 0.0f);
        CHECK(rotation.c0 == 0.0f);
        CHECK(rotation.c1 == 0.0f);
        CHECK(rotation.c2 == 1.0f);
        CHECK(rotation.c3 == 0.0f);
        CHECK(rotation.d0 == 0.0f);
        CHECK(rotation.d1 == 0.0f);
        CHECK(rotation.d2 == 0.0f);
        CHECK(rotation.d3 == 1.0f);
    }
}

TEST_CASE("C44Matrix", "[matrix]") {
    SECTION("constructs with default constructor") {
        C44Matrix matrix;
        CHECK(matrix.a0 == 1.0f);
        CHECK(matrix.a1 == 0.0f);
        CHECK(matrix.a2 == 0.0f);
        CHECK(matrix.a3 == 0.0f);
        CHECK(matrix.b0 == 0.0f);
        CHECK(matrix.b1 == 1.0f);
        CHECK(matrix.b2 == 0.0f);
        CHECK(matrix.b3 == 0.0f);
        CHECK(matrix.c0 == 0.0f);
        CHECK(matrix.c1 == 0.0f);
        CHECK(matrix.c2 == 1.0f);
        CHECK(matrix.c3 == 0.0f);
        CHECK(matrix.d0 == 0.0f);
        CHECK(matrix.d1 == 0.0f);
        CHECK(matrix.d2 == 0.0f);
        CHECK(matrix.d3 == 1.0f);
    }

    SECTION("constructs with element constructor") {
        auto matrix = C44Matrix(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
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

TEST_CASE("C44Matrix::Inverse", "[matrix]") {
    SECTION("returns inverse of identity matrix") {
        C44Matrix matrix;
        auto inverse = matrix.Inverse(matrix.Determinant());
        CHECK(inverse.a0 == 1.0f);
        CHECK(inverse.a1 == 0.0f);
        CHECK(inverse.a2 == 0.0f);
        CHECK(inverse.a3 == 0.0f);
        CHECK(inverse.b0 == 0.0f);
        CHECK(inverse.b1 == 1.0f);
        CHECK(inverse.b2 == 0.0f);
        CHECK(inverse.b3 == 0.0f);
        CHECK(inverse.c0 == 0.0f);
        CHECK(inverse.c1 == 0.0f);
        CHECK(inverse.c2 == 1.0f);
        CHECK(inverse.c3 == 0.0f);
        CHECK(inverse.d0 == 0.0f);
        CHECK(inverse.d1 == 0.0f);
        CHECK(inverse.d2 == 0.0f);
        CHECK(inverse.d3 == 1.0f);
    }

    SECTION("returns inverse of non-identity matrix") {
        auto matrix = C44Matrix(1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f);
        auto inverse = matrix.Inverse(matrix.Determinant());
        CHECK(inverse.a0 == 0.25f);
        CHECK(inverse.a1 == 0.25f);
        CHECK(inverse.a2 == 0.25f);
        CHECK(inverse.a3 == -0.25f);
        CHECK(inverse.b0 == 0.25f);
        CHECK(inverse.b1 == 0.25f);
        CHECK(inverse.b2 == -0.25f);
        CHECK(inverse.b3 == 0.25f);
        CHECK(inverse.c0 == 0.25f);
        CHECK(inverse.c1 == -0.25f);
        CHECK(inverse.c2 == 0.25f);
        CHECK(inverse.c3 == 0.25f);
        CHECK(inverse.d0 == -0.25f);
        CHECK(inverse.d1 == 0.25f);
        CHECK(inverse.d2 == 0.25f);
        CHECK(inverse.d3 == 0.25f);
    }

    SECTION("does not modify self") {
        auto matrix = C44Matrix(1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 1.0f);
        auto inverse = matrix.Inverse(matrix.Determinant());
        CHECK(matrix.a0 == 1.0f);
        CHECK(matrix.a1 == 1.0f);
        CHECK(matrix.a2 == 1.0f);
        CHECK(matrix.a3 == -1.0f);
        CHECK(matrix.b0 == 1.0f);
        CHECK(matrix.b1 == 1.0f);
        CHECK(matrix.b2 == -1.0f);
        CHECK(matrix.b3 == 1.0f);
        CHECK(matrix.c0 == 1.0f);
        CHECK(matrix.c1 == -1.0f);
        CHECK(matrix.c2 == 1.0f);
        CHECK(matrix.c3 == 1.0f);
        CHECK(matrix.d0 == -1.0f);
        CHECK(matrix.d1 == 1.0f);
        CHECK(matrix.d2 == 1.0f);
        CHECK(matrix.d3 == 1.0f);
    }
}

TEST_CASE("C44Matrix::RotateAroundZ", "[matrix]") {
    SECTION("rotates around z-axis by given angle") {
        auto matrix = C44Matrix(1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 1.0f, 0.0f, 20.0f, 30.0f, 40.0f, 1.0f);
        matrix.RotateAroundZ(3.1415927f);
        CHECK(matrix.a0 == Approx(-1.0f));
        CHECK(matrix.a1 == Approx(-1.0f));
        CHECK(matrix.a2 == Approx(-1.0f));
        CHECK(matrix.a3 == 0.0f);
        CHECK(matrix.b0 == Approx(-1.0f));
        CHECK(matrix.b1 == Approx(-1.0f));
        CHECK(matrix.b2 == Approx(1.0f));
        CHECK(matrix.b3 == 0.0f);
        CHECK(matrix.c0 == Approx(1.0f));
        CHECK(matrix.c1 == Approx(-1.0f));
        CHECK(matrix.c2 == Approx(1.0f));
        CHECK(matrix.c3 == 0.0f);
        CHECK(matrix.d0 == 20.0f);
        CHECK(matrix.d1 == 30.0f);
        CHECK(matrix.d2 == 40.0f);
        CHECK(matrix.d3 == 1.0f);
    }
}

TEST_CASE("C44Matrix global operators", "[matrix]") {
    SECTION("C44Matrix * float") {
        auto matrix1 = C44Matrix(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
        auto matrix2 = matrix1 * 2.0f;
        CHECK(matrix2.a0 == 2.0f);
        CHECK(matrix2.a1 == 4.0f);
        CHECK(matrix2.a2 == 6.0f);
        CHECK(matrix2.a3 == 8.0f);
        CHECK(matrix2.b0 == 10.0f);
        CHECK(matrix2.b1 == 12.0f);
        CHECK(matrix2.b2 == 14.0f);
        CHECK(matrix2.b3 == 16.0f);
        CHECK(matrix2.c0 == 18.0f);
        CHECK(matrix2.c1 == 20.0f);
        CHECK(matrix2.c2 == 22.0f);
        CHECK(matrix2.c3 == 24.0f);
        CHECK(matrix2.d0 == 26.0f);
        CHECK(matrix2.d1 == 28.0f);
        CHECK(matrix2.d2 == 30.0f);
        CHECK(matrix2.d3 == 32.0f);
    }

    SECTION("C44Matrix * C44Matrix") {
        auto matrix1 = C44Matrix(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
        auto matrix2 = C44Matrix(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f);
        auto matrix3 = matrix1 * matrix2;
        CHECK(matrix3.a0 == 90.0f);
        CHECK(matrix3.a1 == 100.0f);
        CHECK(matrix3.a2 == 110.0f);
        CHECK(matrix3.a3 == 120.0f);
        CHECK(matrix3.b0 == 202.0f);
        CHECK(matrix3.b1 == 228.0f);
        CHECK(matrix3.b2 == 254.0f);
        CHECK(matrix3.b3 == 280.0f);
        CHECK(matrix3.c0 == 314.0f);
        CHECK(matrix3.c1 == 356.0f);
        CHECK(matrix3.c2 == 398.0f);
        CHECK(matrix3.c3 == 440.0f);
        CHECK(matrix3.d0 == 426.0f);
        CHECK(matrix3.d1 == 484.0f);
        CHECK(matrix3.d2 == 542.0f);
        CHECK(matrix3.d3 == 600.0f);
    }
}

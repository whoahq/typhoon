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

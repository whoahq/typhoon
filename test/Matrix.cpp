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
}

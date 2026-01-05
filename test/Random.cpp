#include "tempest/Random.hpp"
#include "test/Test.hpp"

TEST_CASE("CRandom::dice", "[random]") {
    SECTION("generates numbers within range") {
        auto seed = CRndSeed(0xC0D1E2F3);

        for (int32_t i = 0; i < 200; i++) {
            auto result1 = CRandom::dice(0, seed);
            REQUIRE(result1 == 0);

            auto result2 = CRandom::dice(1, seed);
            REQUIRE(result2 == 0);

            auto result3 = CRandom::dice(2, seed);
            REQUIRE(result3 < 2);

            auto result4 = CRandom::dice(10, seed);
            REQUIRE(result4 < 10);

            auto result5 = CRandom::dice(100, seed);
            REQUIRE(result5 < 100);
        }
    }
}

TEST_CASE("CRandom::uint32", "[random]") {
    SECTION("generates expected numbers for given seed") {
        auto seed = CRndSeed(0x294823);

        auto result1 = CRandom::uint32(seed);
        REQUIRE(result1 == 0xC0D0F1AE);

        auto result2 = CRandom::uint32(seed);
        REQUIRE(result2 == 0x5CA56410);
    }
}

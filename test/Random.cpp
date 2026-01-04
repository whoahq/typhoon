#include "tempest/Random.hpp"
#include "test/Test.hpp"

TEST_CASE("CRandom::uint32", "[random]") {
    SECTION("generates expected numbers for given seed") {
        auto seed = CRndSeed(0x294823);

        auto result1 = CRandom::uint32(seed);
        REQUIRE(result1 == 0xC0D0F1AE);

        auto result2 = CRandom::uint32(seed);
        REQUIRE(result2 == 0x5CA56410);
    }
}

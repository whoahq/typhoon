#include "tempest/Rect.hpp"
#include "test/Test.hpp"

TEST_CASE("CRect", "[rect]") {
    SECTION("constructs with default constructor") {
        CRect rect;
        CHECK(rect.minY == 0.0f);
        CHECK(rect.minX == 0.0f);
        CHECK(rect.maxY == 0.0f);
        CHECK(rect.maxX == 0.0f);
    }

    SECTION("constructs with minY minX maxY maxX constructor") {
        auto rect = CRect(1.0f, 2.0f, 3.0f, 4.0f);
        CHECK(rect.minY == 1.0f);
        CHECK(rect.minX == 2.0f);
        CHECK(rect.maxY == 3.0f);
        CHECK(rect.maxX == 4.0f);
    }
}

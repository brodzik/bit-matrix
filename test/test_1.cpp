#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("default initialization")
{
    BitMatrix bm(3, 3);

    REQUIRE(bm.getBit(0, 0) == false);
    REQUIRE(bm.getBit(1, 0) == false);
    REQUIRE(bm.getBit(2, 0) == false);

    REQUIRE(bm.getBit(0, 1) == false);
    REQUIRE(bm.getBit(1, 1) == false);
    REQUIRE(bm.getBit(2, 1) == false);

    REQUIRE(bm.getBit(0, 2) == false);
    REQUIRE(bm.getBit(1, 2) == false);
    REQUIRE(bm.getBit(2, 2) == false);
}

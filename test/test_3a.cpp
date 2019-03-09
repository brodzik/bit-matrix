#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("get/set individual bits")
{
    // 1 0 0 1
    // 0 1 0 0
    // 0 0 1 0
    // 1 0 0 1

    BitMatrix bm(4, 4);

    bm.setBit(0, 0, true);
    bm.setBit(1, 0, false);
    bm.setBit(2, 0, false);
    bm.setBit(3, 0, true);

    bm.setBit(0, 1, false);
    bm.setBit(1, 1, true);
    bm.setBit(2, 1, false);
    bm.setBit(3, 1, false);

    bm.setBit(0, 2, false);
    bm.setBit(1, 2, false);
    bm.setBit(2, 2, true);
    bm.setBit(3, 2, false);

    bm.setBit(0, 3, true);
    bm.setBit(1, 3, false);
    bm.setBit(2, 3, false);
    bm.setBit(3, 3, true);

    REQUIRE(bm.getBit(0, 0) == true);
    REQUIRE(bm.getBit(1, 0) == false);
    REQUIRE(bm.getBit(2, 0) == false);
    REQUIRE(bm.getBit(3, 0) == true);

    REQUIRE(bm.getBit(0, 1) == false);
    REQUIRE(bm.getBit(1, 1) == true);
    REQUIRE(bm.getBit(2, 1) == false);
    REQUIRE(bm.getBit(3, 1) == false);

    REQUIRE(bm.getBit(0, 2) == false);
    REQUIRE(bm.getBit(1, 2) == false);
    REQUIRE(bm.getBit(2, 2) == true);
    REQUIRE(bm.getBit(3, 2) == false);

    REQUIRE(bm.getBit(0, 3) == true);
    REQUIRE(bm.getBit(1, 3) == false);
    REQUIRE(bm.getBit(2, 3) == false);
    REQUIRE(bm.getBit(3, 3) == true);
}

#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("get/set individual bits")
{
    BitMatrix<3, 5> bm;

    bm.setBit(0, 0, true);
    bm.setBit(1, 0, false);
    bm.setBit(2, 0, false);
    bm.setBit(0, 1, false);
    bm.setBit(1, 1, true);
    bm.setBit(2, 1, false);
    bm.setBit(0, 2, false);
    bm.setBit(1, 2, false);
    bm.setBit(2, 2, true);
    bm.setBit(0, 3, true);
    bm.setBit(1, 3, false);
    bm.setBit(2, 3, false);
    bm.setBit(0, 4, false);
    bm.setBit(1, 4, true);
    bm.setBit(2, 4, true);

    CHECK(bm.getBit(0, 0) == true);
    CHECK(bm.getBit(1, 0) == false);
    CHECK(bm.getBit(2, 0) == false);
    CHECK(bm.getBit(0, 1) == false);
    CHECK(bm.getBit(1, 1) == true);
    CHECK(bm.getBit(2, 1) == false);
    CHECK(bm.getBit(0, 2) == false);
    CHECK(bm.getBit(1, 2) == false);
    CHECK(bm.getBit(2, 2) == true);
    CHECK(bm.getBit(0, 3) == true);
    CHECK(bm.getBit(1, 3) == false);
    CHECK(bm.getBit(2, 3) == false);
    CHECK(bm.getBit(0, 4) == false);
    CHECK(bm.getBit(1, 4) == true);
    CHECK(bm.getBit(2, 4) == true);
}

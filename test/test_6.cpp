#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("set row")
{
    // 0 1 0 0 0 1 0 1 1 0
    // 1 0 0 0 0 0 0 0 1 1
    // 0 0 0 0 0 0 0 0 0 0
    // 1 1 1 1 1 1 1 1 1 1
    // 0 0 0 0 0 0 0 0 0 1

    BitMatrix bm(10, 5);

    bm.setRow(0, 278);
    bm.setRow(1, 515);
    bm.setRow(2, 0);
    bm.setRow(3, 1023);
    bm.setRow(4, 1);

    bm.printRawData();
    bm.printData();

    CHECK(bm.getRow(0) == 278);
    CHECK(bm.getRow(1) == 515);
    CHECK(bm.getRow(2) == 0);
    CHECK(bm.getRow(3) == 1023);
    CHECK(bm.getRow(4) == 1);
}

#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("get column")
{
    BitMatrix bm(3, 5);

    bm.setBit(0, 0, false);
    bm.setBit(1, 0, true);
    bm.setBit(2, 0, true);
    bm.setBit(0, 1, true);
    bm.setBit(1, 1, false);
    bm.setBit(2, 1, false);
    bm.setBit(0, 2, true);
    bm.setBit(1, 2, true);
    bm.setBit(2, 2, true);
    bm.setBit(0, 3, false);
    bm.setBit(1, 3, false);
    bm.setBit(2, 3, false);
    bm.setBit(0, 4, false);
    bm.setBit(1, 4, true);
    bm.setBit(2, 4, false);

    bm.printRawData();
    bm.printData();

    CHECK(bm.getColumn(0) == 12);
    CHECK(bm.getColumn(1) == 21);
    CHECK(bm.getColumn(2) == 20);
}

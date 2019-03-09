#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("set column")
{
    BitMatrix bm(6, 14);

    bm.setCol(0, 511);
    bm.setCol(1, 0);
    bm.setCol(2, 1574);
    bm.setCol(3, 16383);
    bm.setCol(4, 8192);
    bm.setCol(5, 9135);

    CHECK(bm.getCol(0) == 511);
    CHECK(bm.getCol(1) == 0);
    CHECK(bm.getCol(2) == 1574);
    CHECK(bm.getCol(3) == 16383);
    CHECK(bm.getCol(4) == 8192);
    CHECK(bm.getCol(5) == 9135);
}

#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("set column")
{
    BitMatrix bm(6, 14);

    bm.setColumn(0, 511);
    bm.setColumn(1, 0);
    bm.setColumn(2, 1574);
    bm.setColumn(3, 16383);
    bm.setColumn(4, 8192);
    bm.setColumn(5, 9135);

    CHECK(bm.getColumn(0) == 511);
    CHECK(bm.getColumn(1) == 0);
    CHECK(bm.getColumn(2) == 1574);
    CHECK(bm.getColumn(3) == 16383);
    CHECK(bm.getColumn(4) == 8192);
    CHECK(bm.getColumn(5) == 9135);
}

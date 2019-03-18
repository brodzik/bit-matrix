#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("big data")
{
    BitMatrix<1000000, 10> bm;

    bm.setRow(0, 11015328558134760310ULL);
    bm.setRow(1, 17446744073709551610ULL);
    bm.setRow(2, 13599019901234612730ULL);

    CHECK(bm.getRow(0) == 11015328558134760310ULL);
    CHECK(bm.getRow(1) == 17446744073709551610ULL);
    CHECK(bm.getRow(2) == 13599019901234612730ULL);
    CHECK(bm.getRow(3) == 0);
    CHECK(bm.getRow(4) == 0);
    CHECK(bm.getRow(5) == 0);
    CHECK(bm.getRow(6) == 0);
    CHECK(bm.getRow(7) == 0);
    CHECK(bm.getRow(8) == 0);
    CHECK(bm.getRow(9) == 0);
    CHECK(bm.getColumn(999999) == 0);
}

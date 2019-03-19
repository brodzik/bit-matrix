#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("swap")
{
    SUBCASE("bits")
    {
        BitMatrix<500, 100> bm;
        bm.setBit(435, 22, true);

        CHECK(bm.getBit(435, 22) == true);
        CHECK(bm.getBit(50, 50) == false);

        bm.swapBits(435, 22, 50, 50);

        CHECK(bm.getBit(435, 22) == false);
        CHECK(bm.getBit(50, 50) == true);

        bm.swapBits(435, 22, 50, 50);

        CHECK(bm.getBit(435, 22) == true);
        CHECK(bm.getBit(50, 50) == false);
    }

    SUBCASE("rows")
    {
        BitMatrix<500, 100> bm;
        bm.setRow(5, 31268);
        bm.setRow(39, 1000);

        CHECK(bm.getRow(5) == 31268);
        CHECK(bm.getRow(39) == 1000);

        bm.swapRows(5, 39);

        CHECK(bm.getRow(5) == 1000);
        CHECK(bm.getRow(39) == 31268);
    }

    SUBCASE("columns")
    {
        BitMatrix<500, 100> bm;
        bm.setColumn(5, 31268);
        bm.setColumn(39, 1000);

        CHECK(bm.getColumn(5) == 31268);
        CHECK(bm.getColumn(39) == 1000);

        bm.swapColumns(5, 39);

        CHECK(bm.getColumn(5) == 1000);
        CHECK(bm.getColumn(39) == 31268);
    }
}

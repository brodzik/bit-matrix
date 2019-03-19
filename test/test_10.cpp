#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("operators")
{
    SUBCASE("&")
    {
        BitMatrix<6, 4> bm1;
        bm1.setRow(0, 46);
        bm1.setRow(1, 6);
        bm1.setRow(2, 42);
        bm1.setRow(3, 1);

        BitMatrix<6, 4> bm2;
        bm2.setRow(0, 54);
        bm2.setRow(1, 1);
        bm2.setRow(2, 15);
        bm2.setRow(3, 63);

        BitMatrix<6, 4> bm3 = bm1 & bm2;

        CHECK(bm1.getRow(0) == 46);
        CHECK(bm1.getRow(1) == 6);
        CHECK(bm1.getRow(2) == 42);
        CHECK(bm1.getRow(3) == 1);

        CHECK(bm2.getRow(0) == 54);
        CHECK(bm2.getRow(1) == 1);
        CHECK(bm2.getRow(2) == 15);
        CHECK(bm2.getRow(3) == 63);

        CHECK(bm3.getRow(0) == 38);
        CHECK(bm3.getRow(1) == 0);
        CHECK(bm3.getRow(2) == 10);
        CHECK(bm3.getRow(3) == 1);
    }

    SUBCASE("&=")
    {
        BitMatrix<6, 4> bm1;
        bm1.setRow(0, 46);
        bm1.setRow(1, 6);
        bm1.setRow(2, 42);
        bm1.setRow(3, 1);

        BitMatrix<6, 4> bm2;
        bm2.setRow(0, 54);
        bm2.setRow(1, 1);
        bm2.setRow(2, 15);
        bm2.setRow(3, 63);

        bm1 &= bm2;

        CHECK(bm1.getRow(0) == 38);
        CHECK(bm1.getRow(1) == 0);
        CHECK(bm1.getRow(2) == 10);
        CHECK(bm1.getRow(3) == 1);
    }

    SUBCASE("|")
    {
        BitMatrix<6, 4> bm1;
        bm1.setRow(0, 46);
        bm1.setRow(1, 6);
        bm1.setRow(2, 42);
        bm1.setRow(3, 1);

        BitMatrix<6, 4> bm2;
        bm2.setRow(0, 54);
        bm2.setRow(1, 1);
        bm2.setRow(2, 15);
        bm2.setRow(3, 63);

        BitMatrix<6, 4> bm3 = bm1 | bm2;

        CHECK(bm1.getRow(0) == 46);
        CHECK(bm1.getRow(1) == 6);
        CHECK(bm1.getRow(2) == 42);
        CHECK(bm1.getRow(3) == 1);

        CHECK(bm2.getRow(0) == 54);
        CHECK(bm2.getRow(1) == 1);
        CHECK(bm2.getRow(2) == 15);
        CHECK(bm2.getRow(3) == 63);

        CHECK(bm3.getRow(0) == 62);
        CHECK(bm3.getRow(1) == 7);
        CHECK(bm3.getRow(2) == 47);
        CHECK(bm3.getRow(3) == 63);
    }

    SUBCASE("|=")
    {
        BitMatrix<6, 4> bm1;
        bm1.setRow(0, 46);
        bm1.setRow(1, 6);
        bm1.setRow(2, 42);
        bm1.setRow(3, 1);

        BitMatrix<6, 4> bm2;
        bm2.setRow(0, 54);
        bm2.setRow(1, 1);
        bm2.setRow(2, 15);
        bm2.setRow(3, 63);

        bm1 |= bm2;

        CHECK(bm1.getRow(0) == 62);
        CHECK(bm1.getRow(1) == 7);
        CHECK(bm1.getRow(2) == 47);
        CHECK(bm1.getRow(3) == 63);
    }

    SUBCASE("^")
    {
        BitMatrix<6, 4> bm1;
        bm1.setRow(0, 46);
        bm1.setRow(1, 6);
        bm1.setRow(2, 42);
        bm1.setRow(3, 1);

        BitMatrix<6, 4> bm2;
        bm2.setRow(0, 54);
        bm2.setRow(1, 1);
        bm2.setRow(2, 15);
        bm2.setRow(3, 63);

        BitMatrix<6, 4> bm3 = bm1 ^ bm2;

        CHECK(bm1.getRow(0) == 46);
        CHECK(bm1.getRow(1) == 6);
        CHECK(bm1.getRow(2) == 42);
        CHECK(bm1.getRow(3) == 1);

        CHECK(bm2.getRow(0) == 54);
        CHECK(bm2.getRow(1) == 1);
        CHECK(bm2.getRow(2) == 15);
        CHECK(bm2.getRow(3) == 63);

        CHECK(bm3.getRow(0) == 24);
        CHECK(bm3.getRow(1) == 7);
        CHECK(bm3.getRow(2) == 37);
        CHECK(bm3.getRow(3) == 62);
    }

    SUBCASE("^=")
    {
        BitMatrix<6, 4> bm1;
        bm1.setRow(0, 46);
        bm1.setRow(1, 6);
        bm1.setRow(2, 42);
        bm1.setRow(3, 1);

        BitMatrix<6, 4> bm2;
        bm2.setRow(0, 54);
        bm2.setRow(1, 1);
        bm2.setRow(2, 15);
        bm2.setRow(3, 63);

        bm1 ^= bm2;

        CHECK(bm1.getRow(0) == 24);
        CHECK(bm1.getRow(1) == 7);
        CHECK(bm1.getRow(2) == 37);
        CHECK(bm1.getRow(3) == 62);
    }
}

#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("assignment")
{
    SUBCASE("operator")
    {
        BitMatrix<10, 3> bm;

        bm.setRow(0, 953);
        bm.setRow(1, 17);
        bm.setRow(2, 1023);

        CHECK(bm.getRow(0) == 953);
        CHECK(bm.getRow(1) == 17);
        CHECK(bm.getRow(2) == 1023);

        BitMatrix<10, 3> bm_copy = bm;

        CHECK(bm_copy.getRow(0) == 953);
        CHECK(bm_copy.getRow(1) == 17);
        CHECK(bm_copy.getRow(2) == 1023);
    }

    SUBCASE("constructor")
    {
        BitMatrix<10, 3> bm;

        bm.setRow(0, 953);
        bm.setRow(1, 17);
        bm.setRow(2, 1023);

        CHECK(bm.getRow(0) == 953);
        CHECK(bm.getRow(1) == 17);
        CHECK(bm.getRow(2) == 1023);

        BitMatrix<10, 3> bm_copy(bm);

        CHECK(bm_copy.getRow(0) == 953);
        CHECK(bm_copy.getRow(1) == 17);
        CHECK(bm_copy.getRow(2) == 1023);
    }
}

#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("initialization")
{
    BitMatrix<3, 3> bm;

    CHECK(bm.getBit(0, 0) == false);
    CHECK(bm.getBit(1, 0) == false);
    CHECK(bm.getBit(2, 0) == false);
    CHECK(bm.getBit(0, 1) == false);
    CHECK(bm.getBit(1, 1) == false);
    CHECK(bm.getBit(2, 1) == false);
    CHECK(bm.getBit(0, 2) == false);
    CHECK(bm.getBit(1, 2) == false);
    CHECK(bm.getBit(2, 2) == false);
}

#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("set a single bit")
{
    BitMatrix<1, 1> bm;

    bm.setBit(0, 0, true);

    CHECK(bm.getBit(0, 0) == true);
}

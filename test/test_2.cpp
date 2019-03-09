#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("single bit")
{
    BitMatrix bm(1, 1);

    bm.setBit(0, 0, true);
    bm.setBit(0, 0, false);
    bm.setBit(0, 0, true);

    REQUIRE(bm.getBit(0, 0) == true);
}

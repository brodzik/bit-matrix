#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("set a single bit")
{
    BitMatrix bm(1, 1);

    bm.setBit(0, 0, true);

    bm.printRawData();
    bm.printData();

    CHECK(bm.getBit(0, 0) == true);
}

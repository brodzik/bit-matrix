#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("get/set individual bits")
{
    // 0 0 0 0 0 0 0 0 0 0
    // 1 0 0 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0 0 0 0
    // 0 0 0 0 0 0 0 0 0 0

    BitMatrix bm(10, 5);

    bm.setBit(0, 1, true);

    bm.printRawData();
    bm.printData();
}

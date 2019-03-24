#include "bitmatrix.hpp"
#include "doctest/doctest.h"

TEST_CASE("iterator")
{
    SUBCASE("row")
    {
        BitMatrix<5, 3> bm;

        bm.setRow(0, 23);
        bm.setRow(1, 3);
        bm.setRow(2, 18);

        for (auto it = bm.row_begin(); it != bm.row_end(); ++it)
        {
            std::cout << *it << std::endl;
        }

        auto it = bm.row_begin();

        CHECK(*it == 23);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 18);
    }

    SUBCASE("column")
    {
        BitMatrix<5, 3> bm;

        bm.setRow(0, 23);
        bm.setRow(1, 3);
        bm.setRow(2, 18);

        for (auto it = bm.column_begin(); it != bm.column_end(); ++it)
        {
            std::cout << *it << std::endl;
        }

        auto it = bm.column_begin();

        CHECK(*it == 5);
        ++it;
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 4);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 6);
    }
}

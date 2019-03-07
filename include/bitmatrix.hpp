#pragma once

#include <cmath>

class BitMatrix
{
public:
    BitMatrix(int row_count, int col_count);
    ~BitMatrix();

    bool setRow(int index, int value);
    bool setCol(int index, int value);

    int getRow(int index);
    int getCol(int index);

private:
    int row_count, col_count;
    char *data;
};

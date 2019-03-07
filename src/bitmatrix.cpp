#include "bitmatrix.hpp"

BitMatrix::BitMatrix(int row_count, int col_count)
{
    data = new char[(int)ceil(row_count * col_count / 8.0)];
}

BitMatrix::~BitMatrix()
{
    delete[] data;
}

bool BitMatrix::setRow(int index, int value)
{
    return false;
}

bool BitMatrix::setCol(int index, int value)
{
    return false;
}

int BitMatrix::getRow(int index)
{
    return 0;
}

int BitMatrix::getCol(int index)
{
    return 0;
}

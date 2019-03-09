#include "bitmatrix.hpp"

BitMatrix::BitMatrix(size_t size_x, size_t size_y)
    : size_x(size_x)
    , size_y(size_y)
    , size_data(std::ceil(size_x * size_y / 8.0))
    , data(new char[size_data])
{
    if (size_x <= 0 || size_y <= 0)
    {
        throw;
    }

    std::memset(data, 0, size_data * sizeof(char));
}

BitMatrix::~BitMatrix()
{
    delete[] data;
}

bool BitMatrix::getBit(size_t x, size_t y)
{
    if (x >= size_x || y >= size_y)
    {
        throw;
    }

    int temp = size_y * y + x;

    return (data[temp / 8] >> (temp % 8)) & 1;
}

void BitMatrix::setBit(size_t x, size_t y, bool value)
{
    if (x >= size_x || y >= size_y)
    {
        throw;
    }

    int temp = size_y * y + x;

    if (value)
    {
        data[temp / 8] |= 1 << (temp % 8);
    }
    else
    {
        data[temp / 8] &= ~(1 << (temp % 8));
    }
}

unsigned long long BitMatrix::getRow(size_t y)
{
    if (y >= size_y)
    {
        throw std::out_of_range("y");
    }

    unsigned long long result = 0;

    for (size_t x = 0; x < size_x; ++x)
    {
        if (getBit(x, y))
        {
            result |= 1 << (size_x - x - 1);
        }
    }

    return result;
}

unsigned long long BitMatrix::getCol(size_t x)
{
    if (x >= size_x)
    {
        throw std::out_of_range("x");
    }

    unsigned long long result = 0;

    for (size_t y = 0; y < size_y; ++y)
    {
        if (getBit(x, y))
        {
            result |= 1 << (size_y - y - 1);
        }
    }

    return result;
}

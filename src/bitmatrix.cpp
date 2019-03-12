#include "bitmatrix.hpp"
BitMatrix::BitMatrix(size_t size_x, size_t size_y)
    : size_x(size_x)
    , size_y(size_y)
    , size_data(std::ceil(size_x * size_y / 8.0))
    , data(new char[size_data])
{
    if (size_x == 0)
    {
        throw std::out_of_range("'size_x' cannot be 0");
    }

    if (size_y == 0)
    {
        throw std::out_of_range("'size_y' cannot be 0");
    }

    if (size_data == 0)
    {
        throw std::out_of_range("'size_data' cannot be 0");
    }

    std::memset(data, 0, size_data * sizeof(char));
}

BitMatrix::~BitMatrix()
{
    delete[] data;
}

void BitMatrix::printRawData()
{
    std::cout << "Raw char[] data:" << std::endl;

    for (size_t i = 0; i < size_data; ++i)
    {
        for (size_t j = 0; j < 8; ++j)
        {
            std::cout << ((data[i] >> j) & 1);
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void BitMatrix::printData()
{
    std::cout << "Formatted data:" << std::endl;

    for (size_t y = 0; y < size_y; ++y)
    {
        for (size_t x = 0; x < size_x; ++x)
        {
            std::cout << getBit(x, y);
        }

        std::cout << std::endl;
    }
}

void BitMatrix::setBit(size_t x, size_t y, bool value)
{
    if (x >= size_x)
    {
        throw std::out_of_range("'x' must be less than 'size_x'");
    }

    if (y >= size_y)
    {
        throw std::out_of_range("'y' must be less than 'size_y'");
    }

    int temp = size_x * y + x;

    if (value)
    {
        data[temp / 8] |= 1 << (temp % 8);
    }
    else
    {
        data[temp / 8] &= ~(1 << (temp % 8));
    }
}

void BitMatrix::setRow(size_t y, unsigned long long value)
{
    if (y >= size_y)
    {
        throw std::out_of_range("'y' must be less than 'size_y'");
    }

    if (log2(value) >= size_x)
    {
        throw std::out_of_range("'value' must have less than 'size_x' bits");
    }

    for (size_t x = 0; x < size_x; ++x)
    {
        setBit(x, y, (value >> (size_x - x - 1)) & 1);
    }
}

void BitMatrix::setColumn(size_t x, unsigned long long value)
{
    if (x >= size_x)
    {
        throw std::out_of_range("'x' must be less than 'size_x'");
    }

    if (log2(value) >= size_y)
    {
        throw std::out_of_range("'value' must have less than 'size_y' bits");
    }

    for (size_t y = 0; y < size_y; ++y)
    {
        setBit(x, y, (value >> (size_y - y - 1)) & 1);
    }
}

bool BitMatrix::getBit(size_t x, size_t y)
{
    if (x >= size_x)
    {
        throw std::out_of_range("'x' must be less than 'size_x'");
    }

    if (y >= size_y)
    {
        throw std::out_of_range("'y' must be less than 'size_y'");
    }

    int temp = size_x * y + x;

    return (data[temp / 8] >> (temp % 8)) & 1;
}

unsigned long long BitMatrix::getRow(size_t y)
{
    if (y >= size_y)
    {
        throw std::out_of_range("'y' must be less than 'size_y'");
    }

    unsigned long long result = 0;

    for (size_t x = 0; x < size_x; ++x)
    {
        if (getBit(x, y))
        {
            result |= 1ULL << (size_x - x - 1);
        }
    }

    return result;
}

unsigned long long BitMatrix::getColumn(size_t x)
{
    if (x >= size_x)
    {
        throw std::out_of_range("'x' must be less than 'size_x'");
    }

    unsigned long long result = 0;

    for (size_t y = 0; y < size_y; ++y)
    {
        if (getBit(x, y))
        {
            result |= 1ULL << (size_y - y - 1);
        }
    }

    return result;
}

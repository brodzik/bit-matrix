#pragma once

#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>

template <std::size_t size_x, std::size_t size_y>
class BitMatrix
{
public:
    BitMatrix()
    {
        if (size_x == 0)
        {
            throw std::out_of_range("'size_x' cannot be 0");
        }

        if (size_y == 0)
        {
            throw std::out_of_range("'size_y' cannot be 0");
        }
    }

    void printData()
    {
        for (size_t y = 0; y < size_y; ++y)
        {
            for (size_t x = 0; x < size_x; ++x)
            {
                std::cout << getBit(x, y);
            }

            std::cout << std::endl;
        }
    }

    bool getBit(size_t x, size_t y)
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

    void setBit(size_t x, size_t y, bool value)
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

    unsigned long long getRow(size_t y)
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

    void setRow(size_t y, unsigned long long value)
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

    unsigned long long getColumn(size_t x)
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

    void setColumn(size_t x, unsigned long long value)
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

private:
    char data[size_x * size_y / 8 + 1] = {0};
};

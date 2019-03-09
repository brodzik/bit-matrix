#pragma once

#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>

class BitMatrix
{
public:
    BitMatrix(size_t size_x, size_t size_y);
    ~BitMatrix();

    void printRawData();
    void printData();

    void setBit(size_t x, size_t y, bool value);
    void setRow(size_t y, unsigned long long value);
    void setColumn(size_t x, unsigned long long value);

    bool getBit(size_t x, size_t y);
    unsigned long long getRow(size_t y);
    unsigned long long getColumn(size_t x);

private:
    size_t size_x, size_y, size_data;
    char *data;
};

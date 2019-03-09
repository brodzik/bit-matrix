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

    bool getBit(size_t x, size_t y);
    void setBit(size_t x, size_t y, bool value);

    unsigned long long getRow(size_t y);
    unsigned long long getCol(size_t x);

    void setRow(size_t y, unsigned long long value);
    void setCol(size_t x, unsigned long long value);

private:
    size_t size_x, size_y, size_data;
    char *data;
};

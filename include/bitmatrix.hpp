#pragma once

#include <cmath>
#include <cstring>

class BitMatrix
{
public:
    BitMatrix(size_t size_x, size_t size_y);
    ~BitMatrix();

    bool getBit(size_t x, size_t y);
    void setBit(size_t x, size_t y, bool value);

private:
    size_t size_x, size_y, size_data;
    char *data;
};

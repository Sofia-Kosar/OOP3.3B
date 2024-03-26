#pragma once
#include"Pair.h"
#include <iostream>
#include <string>
using namespace std;
class LongLong : public Pair {
public:
    LongLong() : Pair(0, 0) {}
    LongLong(long first, long second) : Pair(first, second) {}
    LongLong& operator++();
    LongLong operator++(int);
    LongLong& operator--();
    LongLong operator--(int);
    friend LongLong operator+(const LongLong& left, const LongLong& right);
    friend LongLong operator*(const LongLong& left, const LongLong& right);
};
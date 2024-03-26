#include "LongLong.h"
 
LongLong& LongLong::operator++() {
    if (++a == 0)
        ++a;
    return *this;
}

LongLong LongLong::operator++(int) {
    LongLong temp(*this);
    ++(*this);
    return temp;
}

LongLong& LongLong::operator--() {
    if (b-- == 0)
        --b;
    return *this;
}

LongLong LongLong::operator--(int) {
    LongLong temp(*this);
    --(*this);
    return temp;
}
LongLong operator+(const LongLong& left, const LongLong& right) {
    unsigned long sum_low = left.getB() + right.getB();
    unsigned long sum_high = left.getA() + right.getA();

    if (sum_low < left.getB())
        sum_high++;

    return LongLong(sum_high, sum_low);
}

LongLong operator*(const LongLong& left, const LongLong& right) {
    unsigned long aLow = left.getB();
    unsigned long aHigh = left.getA();
    unsigned long bLow = right.getB();
    unsigned long bHigh = right.getA();

    unsigned long long res1 = static_cast<unsigned long long>(aLow) * bLow;
    unsigned long long res2 = static_cast<unsigned long long>(aLow) * bHigh;
    unsigned long long res3 = static_cast<unsigned long long>(aHigh) * bLow;

    unsigned long long sum = res1 + (res2 << 32) + (res3 << 32);

    unsigned int resultLow = static_cast<unsigned int>(sum & 0xFFFFFFFF);
    unsigned int resultHigh = static_cast<unsigned int>((sum >> 32) & 0xFFFFFFFF);

    return LongLong(resultHigh, resultLow);
}
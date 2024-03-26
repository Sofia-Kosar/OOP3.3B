#include "Pair.h"
#include <sstream>

Pair::operator std::string() const {
    std::stringstream sout;
    sout << "a = " << a << "\n" << "b = " << b << "\n";
    return sout.str();
}

Pair& Pair::operator=(const Pair& obj) {
    a = obj.a;
    b = obj.b;
    return *this;
}

Pair::Pair() : a(0), b(0) {}

Pair::Pair(long first, long second) : a(first), b(second) {}

std::istream& operator>>(std::istream& in, Pair& obj) {
    std::cout << "a = ";
    in >> obj.a;
    std::cout << "b = ";
    in >> obj.b;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pair& obj) {
    out << std::string(obj);
    return out;
}


bool operator!=(const Pair& obj1, const Pair& obj2) {
    return !(obj1 == obj2);
}


bool operator<=(const Pair& obj1, const Pair& obj2) {
    return (obj1 < obj2) || (obj1 == obj2);
}


bool operator>=(const Pair& obj1, const Pair& obj2) {
    return !(obj1 < obj2);
}
bool operator>(const Pair& obj1, const Pair& obj2) {
    return obj1.a > obj2.a && obj1.b > obj2.b;
}

bool operator<(const Pair& obj1, const Pair& obj2) {
    return !(obj1 > obj2);
}

bool operator==(const Pair& obj1, const Pair& obj2) {
    return obj1.a == obj2.a && obj1.b == obj2.b;
}

Pair operator+(const Pair& left, const Pair& right) {
    unsigned long sum_low = left.getB() + right.getB();
    unsigned long sum_high = left.getA() + right.getA();

    if (sum_low < left.getB())
        sum_high++;

    return Pair(sum_high, sum_low);
}

Pair operator*(const Pair& left, const Pair& right) {
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

    return Pair(resultHigh, resultLow);
}
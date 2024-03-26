#pragma once

#include <string>
#include <iostream>

class Pair {
protected:
    long a;
    long b;
public:
    long getA() const { return a; }
    long getB() const { return b; }
    void setA(long value) { a = value; }
    void setB(long value) { b = value; }

    Pair();
    Pair(long first, long second);
    operator std::string() const;
    Pair& operator=(const Pair& obj);
    friend std::ostream& operator<<(std::ostream& out, const Pair& obj);
    friend std::istream& operator>>(std::istream& in, Pair& obj);
    friend bool operator==(const Pair& obj1, const Pair& obj2);
    friend bool operator!=(const Pair& obj1, const Pair& obj2);
    friend bool operator<(const Pair& obj1, const Pair& obj2);
    friend bool operator<=(const Pair& obj1, const Pair& obj2);
    friend bool operator>(const Pair& obj1, const Pair& obj2);
    friend bool operator>=(const Pair& obj1, const Pair& obj2);
    friend Pair operator+(const Pair& left, const Pair& right);
    friend Pair operator*(const Pair& left, const Pair& right);
};

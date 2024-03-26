#include "Pair.h"
#include "LongLong.h"
#include <iostream>
using namespace std;

int main() {
    Pair pair1, pair2, pair3;
    cout << "Enter values for pair1:" << endl;
    cin >> pair1;
    cout << "Enter values for pair2:" << endl;
    cin >> pair2;
   
    // Використання операторів порівняння
    cout << "pair1 > pair2: " << (pair1 > pair2) << endl;
    cout << "pair1 < pair2: " << (pair1 < pair2) << endl;
    cout << "pair1 == pair2: " << (pair1 == pair2) << endl;
    cout << "pair1 >= pair2: " << (pair1 >= pair2) << endl;
    cout << "pair1 <=pair2: " << (pair1 <= pair2) << endl;
    cout << "pair1 !== pair2: " << (pair1 != pair2) << endl;
   

    // Використання операторів додавання і множення
    LongLong long1(pair1.getA(), pair1.getB());
    LongLong long2(pair2.getA(), pair2.getB());
    LongLong long3(pair3.getA(), pair3.getB());
    LongLong sum = long1 + long2;
    LongLong product = long1 * long2;

    cout << "pair1 + pair2: " << sum << std::endl;
    cout << "pair1 * pair2: " << product << std::endl;

    // Використання операторів інкременту та декременту
    LongLong incremented = ++sum;
    cout << "Incremented sum: " << incremented << std::endl;

    LongLong decremented = --sum;
    cout << "Decremented sum: " << decremented << std::endl;

    return 0;
}

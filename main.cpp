#include <iostream>
#include "TimePoint.hpp"

int main() {
    TimePoint a;
    std::cout<< "Введите первый момент времени" << std::endl;
    std::cin >> a;
    TimePoint b;
    std::cout<< "Введите второй момент временни" << std::endl;
    std::cin >> b;
    TimePoint c;
    c = a + b;
    std::cout<< "Сумма 1 и 2 момента временни" << std::endl;
    std::cout << c << std::endl;
    c = a - b;
    std::cout<< "Разница 1 и 2 момента временни" << std::endl;
    std::cout << c << std::endl;
    c = b - a;
    std::cout<< "Разница 2 и 1 момента временни" << std::endl;
    std::cout << c << std::endl;
    bool d;
    d = a > b;
    std::cout<< "Сравнение 1 > 2" << std::endl;
    std::cout << d << std::endl;
    d = a < b;
    std::cout<< "Сравнение 1 < 2" << std::endl;
    std::cout << d << std::endl;
    d = a == b;
    std::cout<< "Сравнение 1 == 2" << std::endl;
    std::cout << d << std::endl;
    TimePoint g;
    g = 90000_sec;
    std::cout<< "Пользовательский литерал _sec" << std::endl;
    std::cout<< g << std::endl;
    g = 228_min;
    std::cout<< "Пользовательский литерал _min" << std::endl;
    std::cout<< g << std::endl;
}
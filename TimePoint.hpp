#ifndef TIMEPOINT_HPP
#define TIMEPOINT_HPP

#include <iostream>
#include <cmath>

class TimePoint{
private:
    int hour;
    int minute;
    int second;

    friend TimePoint operator"" _min(unsigned long long a);
    friend TimePoint operator"" _sec(unsigned long long a);
public:
    TimePoint();
    TimePoint(int h, int m, int s);

    void Read(std::istream &is); //ввод
    void Write(std::ostream &os); //вывод

    friend TimePoint operator+ (TimePoint &a, TimePoint &b);//сумма моментов временни
    friend TimePoint operator- (TimePoint &a, TimePoint &b); //разница моментов временни
    TimePoint AddSec(int &sec);//добавь заданное количество секунд
    TimePoint SubtractSec(int &sec);//отнеми заданное количество секунд
    TimePoint ToTpFromSec(int &sec);//Перевод в Timepoint из секунд
    TimePoint ToTpFromMin(int &min);//Первод в Timepoint из минут

    int HowManyTimesBigger(TimePoint &a);//Во сколько раз больше(меньше)
    bool IsCorrect();//проверка правильности ввода данных
    int ToSec();//Перевод из TimePoint в секунды
    int ToMinute();//Перевод из TimePoint в минуты

    friend bool operator>(TimePoint &a, TimePoint &b);//перегрущка сравнения
    friend bool operator<(TimePoint &a, TimePoint &b);//same
    friend bool operator== (TimePoint &a, TimePoint &b);//same

    friend std::ostream& operator<< (std::ostream &out, const TimePoint &point);//перегрузка вывода
    friend std::istream& operator>> (std::istream &in, TimePoint &point);//перегрузка ввода
};

TimePoint operator "" _min(unsigned long long a);//пользовательский литерал:переводит заданое количество минут в TP
TimePoint operator "" _sec(unsigned long long a);//пользовательский литерал:переводит заданое количество секунд в TP

#endif //LAB2_TIMEPOINT_HPP
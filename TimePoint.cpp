#include "TimePoint.hpp"
#include <sstream>

TimePoint::TimePoint() {
    second = 0;
    minute = 0;
    hour = 0;
}

TimePoint::TimePoint(int h, int m, int s) {
    hour=h;
    minute=m;
    second=s;
}

void TimePoint::Read(std::istream &is){
    is >> hour >> minute >> second;
}

void TimePoint::Write(std::ostream &os) {
    os << hour << ":" << minute << ":" << second << std::endl;
}

int TimePoint::ToSec() {
    int result;
    result = second + minute*60 + hour*3600;
    return result;
}

int TimePoint::ToMinute() {
    int result;
    result = ToSec() / 60;
    return result;
}

TimePoint TimePoint::ToTpFromSec(int &sec) {
    TimePoint result;
    result.hour = sec / 3600;
    result.minute = sec / 60 - result.hour*60;
    result.second= sec - (result.minute)*60 -(result.hour)*3600;
    return result;
}

TimePoint TimePoint::ToTpFromMin(int &min) {
    TimePoint result;
    result.hour = min / 60;
    result.minute= min - (result.hour)*60;
    return result;
}

TimePoint operator+ (TimePoint &a, TimePoint &b){
    TimePoint result;
    int normal = (a.ToSec() + b.ToSec()) % 86400;
    return result.ToTpFromSec(normal);
}

TimePoint operator- (TimePoint &a, TimePoint &b) {
    TimePoint result;
    int normal = (a.ToSec() - b.ToSec());
    if(normal >= 0){
        return result.ToTpFromSec(normal);
    } else {
        normal+=86400;
        return result.ToTpFromSec(normal);
    }
}

TimePoint TimePoint::AddSec(int &sec) {
    TimePoint result;
    int normal = (ToSec() + sec) % 86400;
    return result.ToTpFromSec(normal);
}

TimePoint TimePoint::SubtractSec(int &sec) {
    TimePoint result;
    int normal = (ToSec() - sec);
    if(normal >= 0){
        return result.ToTpFromSec(normal);
    } else {
        normal+=86400;
        return result.ToTpFromSec(normal);
    };
}

int TimePoint::HowManyTimesBigger(TimePoint &a) {
    int result = (ToSec()) / (a.ToSec());
    return result;
}

bool TimePoint::IsCorrect(){
    if(hour>24){
        return false;
    } else if(minute>60){
        return false;
    } else if(second>60){
        return false;
    } else {
        return true;
    }
}

bool operator> (TimePoint &a, TimePoint &b){
    return (a.ToSec() > b.ToSec());
}

bool operator< (TimePoint &a, TimePoint &b){
    return (a.ToSec() < b.ToSec());
}

bool operator== (TimePoint &a, TimePoint &b){
    return (a.ToSec()==b.ToSec());
}

std::ostream& operator<< (std::ostream &out, const TimePoint &point) {
    out << point.hour << ":" << point.minute <<":"<< point.second;
    return out;
}


std::istream& operator>> (std::istream &in, TimePoint &point) {
    in >> point.hour >> point.minute >> point.second;
    return in;
}

TimePoint operator "" _min(unsigned long long a){
    unsigned long long b = a / 60;
    unsigned long long c = a % 60;
    TimePoint d(0, 0, 0);
    d.minute=c;
    d.hour=b;
    return d;
}

TimePoint operator "" _sec(unsigned long long a){
    unsigned long long h = a / 3600;
    unsigned long long m = a/60 - h*60;
    unsigned long long s = a - h*3600 - m*60;
    TimePoint d(0, 0, 0);
    d.hour =h;
    d.minute=m;
    d.second=s;
    return d;
}

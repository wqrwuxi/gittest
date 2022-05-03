#include "mytime.h"
#include <ostream>

MyTime::MyTime(int h, int m){
    hours_ = h;
    minutes_ = m;
}

void MyTime::AddHour(int h){
    hours_ += h;
}

void MyTime::AddMin(int m){
    //minutes += m % 60;错，m%60后再加到minutes上
    minutes_ += m;
    hours_ += minutes / 60;
    minutes_ %= 60;
}

void MyTime::Reset(int h, int m){
    hours_ = h;
    minutes_ = m;
}

void MyTime::SetHours(int h){
    hours_ = h;
}

void MyTime::SetMinutes(int m){
    minutes_ = m;
}

MyTime operator+(const MyTime &t1, const MyTime &t2){
    MyTime temp;
    temp = t1;
    //temp.AddHour(t2.hours);
    temp.AddMin(t2.minutes_);
    temp.AddHour(t2.hours_);


    // temp.minutes = (t1.minutes + t2.minutes) % 60;
    // temp.hours = (t1.minutes + t2.minutes) / 60 + t1.hours + t2.hours;
    return temp;
}

MyTime operator-(const MyTime &t1, const MyTime &t2){
    MyTime temp;
    int nowMinute = (int)(t1.hours_* 60 + t1.minutes_ - t2.hours_ * 60 - t2.minutes_) % 60;
    //int nowHour = (t1.hours* 60 + t1.minutes - t2.hours * 60 - t2.minutes) / 60;
    int nowHour = (t1.HoursVal()* 60 + t1.MinutesVal() - t2.HoursVal() * 60 - t2.MinutesVal()) / 60;
    temp.SetMinutes(nowMinute);
    //temp.hours = nowHour;
    temp.hours = (t1.hours_* 60 + t1.minutes_ - t2.hours_ * 60 - t2.minutes_) / 60;
    //temp.SetHours(nowHour);
    return temp;
}

MyTime operator*(const MyTime &t, double n){
    MyTime temp;
    int nowMinute = (int)(t.HoursVal() * 60 * n + t.MinutesVal() * n) % 60;
    int nowHour = (t.HoursVal() * 60 * n + t.MinutesVal() * n) / 60;
    temp.SetMinutes(nowMinute);
    temp.SetHours(nowHour);
    return temp;
}

std::ostream& operator<<(std::ostream &os, const MyTime &t){
    os << "hours:" << t.HoursVal() << ", minutes:" << t.MinutesVal() << std::endl; 
    return os;
}
#ifndef MYTIME_H
#define MYTIME_H
#include <ostream>
class MyTime{
public:
    MyTime() : hours(0), minutes(0) {}
    explicit MyTime(int h, int m = 0);
    void AddHour(int h);
    void AddMin(int m);
    void Reset(int h = 0, int m = 0);
    int HoursVal() const {return hours_;}
    int MinutesVal() const {return minutes_;}
    void SetHours(int h);
    void SetMinutes(int m);
    friend MyTime operator+(const MyTime &t1, const MyTime &t2);
    friend MyTime operator-(const MyTime &t1, const MyTime &t2);
    friend MyTime operator*(const MyTime &t, double n);
    friend MyTime operator*(double n, const MyTime &t) {return t * n;}
    /* 更值得注意的是，不写友元时的乘法的写法
        MyTime operator*(double n);默认对象在前，乘数在后
        因此需要再写一个重载才能满足所有乘法的要求
        注意MyTime operator*(double n, const MyTime &t)的写法，很简洁的一个{return t * n;}
     */
    // MyTime operator*(double n);
    friend std::ostream& operator<<(std::ostream &os, const MyTime &t);
    virtual ~MyTime() {}
private:
    int hours_;
    int minutes_;
};

MyTime operator+(const MyTime &t1, const MyTime &t2);
MyTime operator-(const MyTime &t1, const MyTime &t2);
MyTime operator*(const MyTime &t, double n);
std::ostream& operator<<(std::ostream &os, const MyTime &t);

#endif /* MYTIME_H */
#ifndef WALK_H
#define WALK_H
#include <ostream>
namespace Vector{
    class Vector{
        // friend std::ostream& operator<<(std::ostream& cout, Vector& now);
        // friend Vector operator*(double, const Vector&);

    public:
        /* 枚举值，默认是第一个值 */
        enum Mode{
            RECT,
            POL
        };
    
    public:
        Vector() : x_(0.), y_(0.), r_(0.), ang_(0.), mode_(RECT) {}
        /* 以下的这个有参构造函数是为了和Step成员函数做替换，看这两个函数的区别 */
        Vector(double num1, double num2, Mode form = RECT);
        virtual ~Vector() {}
        double GetX() const {return x_;}
        double GetY() const {return y_;}
        double GetR() const {return r_;}
        double GetAng() const {return ang_;}
        void setMode() {mode_ = POL;}
        void Step(double num1, double num2, Mode form);
        Vector operator+(const Vector& another) const;
        // Vector operator-()const;
        friend std::ostream& operator<<(std::ostream& cout, Vector& now);

    private:
        double x_;
        double y_;
        double r_;
        double ang_;
        Mode mode_;

    private:
        void CalR();
        void CalAng();
        void CalX();
        void CalY();
    };

    // std::ostream& operator<<(std::ostream& cout, Vector& now);
    // Vector operator*(double, const Vector&);
    std::ostream& operator<<(std::ostream& cout, Vector& now);
}



#endif /* WALK_H */
#ifndef COMPLEX_H_
#define COMPLEX_H_
//#include <iostream>
#include <ostream>
#include <istream>
class Complex{
public:
    Complex() : real_(0.), imaginary_(0.) {}
    Complex(double real, double imaginary) : real_(real), imaginary_(imaginary) {}
    virtual ~Complex() {}
    Complex operator~() const;
    Complex operator+(const Complex &cplex) const;
    Complex operator-(const Complex &cplex) const;
    Complex operator*(const Complex &cplex) const;
    friend Complex operator*(double num, const Complex &cplex);
    friend Complex operator*(const Complex &cplex, double num) {return num * cplex;}
    friend std::istream& operator>>(std::istream& is, Complex &cplex);
    friend std::ostream& operator<<(std::ostream& os, const Complex &cplex);
private:
    double real_;
    double imaginary_;
};

Complex operator*(double num, const Complex &cplex);
std::istream& operator>>(std::istream& is, Complex &cplex);
std::ostream& operator<<(std::ostream& os, const Complex &cplex);

#endif /* COMPLEX_H_ */
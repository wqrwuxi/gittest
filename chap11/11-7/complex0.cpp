#include "complex0.h"
#include <iostream>

Complex Complex::operator~() const{
    Complex temp;
    temp.real_ = this->real_;
    temp.imaginary_ = -this->imaginary_;
    return temp;
}

Complex Complex::operator+(const Complex &cplex) const{
    Complex temp;
    temp.real_ = this->real_ + cplex.real_;
    temp.imaginary_ = this->imaginary_ + cplex.imaginary_;
    return temp;
}

Complex Complex::operator-(const Complex &cplex) const{
    Complex temp;
    temp.real_ = this->real_ - cplex.real_;
    temp.imaginary_ = this->imaginary_ - cplex.imaginary_;
    return temp;
}

Complex Complex::operator*(const Complex &cplex) const{
    Complex temp;
    temp.real_ = this->real_ * cplex.real_ - this->imaginary_ * cplex.imaginary_;
    temp.imaginary_ = this->real_ * cplex.imaginary_ + this->imaginary_ * cplex.real_;
    return temp;
}

Complex operator*(double num, const Complex &cplex){
    Complex temp;
    temp.real_ = num * cplex.real_;
    temp.imaginary_ = num * cplex.imaginary_;
    return temp;
}

std::istream& operator>>(std::istream& is, Complex &cplex){
    std::cout << "real:";
    is >> cplex.real_;
    //std::cout << "\n";
    std::cout << "imaginary:";
    is >> cplex.imaginary_;
    //std::cout << "\n";
    return is;
}

std::ostream& operator<<(std::ostream& os, const Complex &cplex){
    std::cout << "(" << cplex.real_ << "," << cplex.imaginary_ << "i)";
    return os;
}
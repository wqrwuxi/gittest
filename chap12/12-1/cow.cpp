#include "cow.h"
#include <iostream>
#include <cstring>
using std::strcpy;
using std::cout;
using std::endl;

Cow::Cow() : name_("\0"), hobby_(nullptr), weight_(0.){
    cout << "default constructor  " << this << endl;
}

Cow::Cow(const char* nm, const char* ho, double wt){
    strcpy(name_, nm);
    hobby_ = new char[strlen(ho) + 1];
    strcpy(hobby_, ho);
    weight_ = wt;
    cout << "Cow::Cow(const char* nm, const char* ho, double wt)  " << this << endl;
}

Cow::Cow(const Cow &c){
    strcpy(name_, c.name_);
    hobby_ = new char[strlen(c.hobby_) + 1];
    strcpy(hobby_, c.hobby_);
    weight_ = c.weight_;
    cout << "Cow::Cow(const Cow &c).  " << this << endl;
}

Cow::~Cow(){
    cout << "name: " << name_ << ", hobby: " << hobby_ << ", weight:" << weight_ << ".  " << this << "  ";
    delete [] hobby_;
    cout << "The object is destructed.\n";
}

Cow& Cow::operator=(const Cow &c){
    cout << "Cow& Cow::operator=(const Cow &c)" << this << endl;
    if(this == &c){
        return *this;
    }
    delete [] hobby_;
    strcpy(name_, c.name_);
    hobby_ = new char[strlen(c.hobby_) + 1];
    strcpy(hobby_, c.hobby_);
    weight_ = c.weight_;
    return *this;
}

void Cow::ShowCow() const{
    cout << "name: " << name_ << ", hobby: " << hobby_ << ", weight:" << weight_ << endl;
}
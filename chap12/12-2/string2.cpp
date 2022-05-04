#include "string2.h"
#include <iostream>
#include <cstring>
#include <cctype>
using std::cout;
using std::endl;
using std::strcpy;

int String::num_strings_ = 0;

String::String() : str_(nullptr), len_(0){
    num_strings_++;
    cout << "num:" << num_strings_  << " default constructor:" << this << endl;
    
}

String::String(const char* s){
    len_ = strlen(s);
    str_ = new char[len_ + 1];
    strcpy(str_, s);
    num_strings_++;
    cout << "num:" << num_strings_  << " String::String(const char* s):" << str_ << "  " << this << endl;
}

String::String(const String &s){
    len_ = s.len_;
    str_ = new char[len_ + 1];
    strcpy(str_, s.str_);
    num_strings_++;
    cout << "num:" << num_strings_  << " String::String(const String &s):" << str_ << "  " << this << " ,from: " << &s << endl;
}

String::~String(){
    --num_strings_;
    //num_strings_--;上下两行好像没区别
    cout << "num:" << num_strings_ <<  "  " << str_ << "  " << this << " The object is destructed.\n" ;
    delete [] str_;
}

String& String::StringLow(){
    char *p = str_;
    for(; *p!='\0'; p++){
        *p = tolower(*p);
    }
    return *this;
}

String& String::StringUp(){
    char *p = str_;
    for(; *p!='\0'; p++){
        *p = toupper(*p);
    }
    return *this;
}

int String::CountChar(const char& c) const{
    int count = 0;
    for(int i = 0; i < len_; i++){
        if((*this)[i] == c){
            count++;
        }
    }
    return count;
}

String& String::operator=(const char* s){
    delete [] str_;
    len_ = strlen(s);
    str_ = new char[len_ + 1];
    strcpy(str_, s);
    cout << "String& String::operator=(const char* s):" << str_ << "  " << this << " ,from: " << &s << endl;
    return *this;
}

String& String::operator=(const String &s){
    if(this == &s){
        return *this;
    }
    delete [] str_;
    str_ = new char[s.len_ + 1];
    strcpy(str_, s.str_);
    len_ = s.len_;
    cout << "String& String::operator=(const String &):" << str_ << "  " << this << " ,from:" << &s << endl;
    return *this;
}

String String::operator+(String &s){
    /*
      方案一
    */
    String strNew;
    strNew.len_ = this->len_ + s.len_;
    strNew.str_ = new char[strNew.len_ + 1];

    /* 写法1 */
    strcpy(strNew.str_, str_);
    /* 写法2 */
    //memset(strNew.str_, 0, this->len_ + s.len_ + 1);
    // memcpy(strNew.str_, 0, this->len_ + s.len_ + 1); 错误的！不能要
    //memcpy(strNew.str_, this->str_, this->len_);

    strncat(strNew.str_, s.str_, s.len_);
    return strNew;
}

String String::operator+(const char s[]){
    String strNew;
    strNew.len_ = this->len_ + strlen(s);
    strNew.str_ = new char[strNew.len_ + 1];
    strcpy(strNew.str_, str_);
    strncat(strNew.str_, s, strlen(s));
    return *this;
}

String operator+(const char s[], String &s1){
    String strNew;
    strNew.str_ = new char[strlen(s) + s1.len_ + 1];
    strcpy(strNew.str_, s);
    strcat(strNew.str_, s1.str_);
    strNew.len_ = strlen(s) + s1.len_ + 1;
    return strNew;
}

bool operator<(const String &s1, const String &s2){
    return (strcmp(s1.str_, s2.str_) < 0);
}

// bool operator>(const String &s1, const String &s2){
//     return (strcmp(s1.str_, s2.str_) > 0);
// }

bool operator==(const String &s1, const String &s2){
    return (strcmp(s1.str_, s2.str_) == 0);
}

std::ostream& operator<<(std::ostream& os, const String &s){
    os << s.str_;
    return os;
}

std::istream& operator>>(std::istream& is, String &s){
    //is >> s.str_  错，s.str_都没分配空间

    char temp[String::CINLIM_];
    is.get(temp, String::CINLIM_);
    if(is){
        s = temp; /* 用了=重载 */
    }
    while(is && is.get()!='\n'){
        continue;
    }
    return is;
}
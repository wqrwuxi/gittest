#ifndef STRING_H_
#define STRING_H_
#include <istream>
#include <ostream>

class String{
public:
    String();
    String(const char* s);
    String(const String &);
    virtual ~String();
    int length() const {return len_;}
    String& StringLow();
    String& StringUp();
    int CountChar(const char& c) const;
    String& operator=(const char* s); //自己写会少&
    String& operator=(const String &); //自己写会少&
    char& operator[](int i) {return str_[i];}//C++ primr plusP359
    const char& operator[](int i) const {return str_[i];}//C++ primr plusP359
    String operator+(String &);
    String operator+(const char[]);
    friend String operator+(const char s[], String &s1);
    //friend String& operator+(const char s[], String &s1) {return (s1 + s);}错
    friend bool operator<(const String &s1, const String &s2);//一定是friend么？
    friend bool operator>(const String &s1, const String &s2) {return s2 < s1;}//一定是friend么？
    friend bool operator==(const String &s1, const String &s2);//一定是friend么？
    friend std::ostream& operator<<(std::ostream& os, const String &s);//const还是写不对
    friend std::istream& operator>>(std::istream& is, String &);
    static int HowMany() {return num_strings_;}
private:
    char* str_;
    int len_;
    static int num_strings_;
    static const int CINLIM_ = 80;
};

//int String::num_strings_ = 0;位置不对
String operator+(const char s[], String &s1);
bool operator<(const String &s1, const String &s2);//一定是friend么？
bool operator>(const String &s1, const String &s2);//一定是friend么？
bool operator==(const String &s1, const String &s2);//一定是friend么？
std::ostream& operator<<(std::ostream& os, const String &s);//const还是写不对
std::istream& operator>>(std::istream& is, String &s);

#endif /* STRING_H_ */
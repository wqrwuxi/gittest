#ifndef COW_H_
#define COW_H_

class Cow{
public:
    Cow();
    Cow(const char* nm, const char* ho, double wt);
    Cow(const Cow &c);
    virtual ~Cow();
    Cow& operator=(const Cow &c);
    void ShowCow() const;
private:
    char name_[20];
    char* hobby_;
    double weight_;
};

#endif /* COW_H_ */
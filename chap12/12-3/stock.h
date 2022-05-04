#ifndef STOCK_H_
#define STOCK_H_
#include <string>
#include <ostream>
using std::string;
using std::ostream;

class Stock{
public:
    Stock();
    explicit Stock(const char* co, long n = 0, double pr = 0);
    virtual ~Stock();
    void Buy(long num, double price);
    void Sell(long num, double price);
    void Update(double price);
    const Stock& Topval(const Stock& s) const;
    friend ostream& operator<<(ostream& os,const Stock& s);
private:
    void SetTot() {totalVal_ = shares_ * shareVal_;}

private:
    char* company_;
    int shares_;
    double shareVal_;
    double totalVal_;
};

ostream& operator<<(ostream& os,const Stock& s);

#endif /* STOCK_H_ */
#include "stock.h"
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::strlen;

Stock::Stock(){
    company_ = new char[1];
    company_[0] = '\0';
    shares_ = 0;
    shareVal_ = 0;
    SetTot();
}

Stock::Stock(const char* co, long n, double pr){
    company_ = new char[strlen(co) + 1];
    strcpy(company_, co);
    if(n < 0){
        cout << "Number of shares can not be negative;" << this->company_ << " shares set to 0.\n";
		shares_ = 0;
    }else{
        shares_ = n; //long  VS int??
    }
    shareVal_ = pr;
    SetTot();
}

Stock::~Stock(){
    delete [] company_;
}

void Stock::Buy(long num, double price){
    if (num < 0){
        cout << "Number of shares purchased can't be negative, transaction is aborted.\n";
    }else{
		shares_ += num;
		shareVal_ = price;
		SetTot();
	}
}

void Stock::Sell(long num, double price){
    if (num < 0){
        cout << "Number of shares sold can't be negative, transaction is aborted.\n";
    }else if(num > shares_){
        cout << "You can't sell more than you have, transaction is aborted.\n";
    }else{
        shares_ -= num;
		shareVal_ = price;
		SetTot();
    }
}

void Stock::Update(double price){
    shares_ = price;
    SetTot();
}

const Stock& Stock::Topval(const Stock& s) const{
    if (s.totalVal_ > this->totalVal_){
        return s;
    }
    return *this;
}

ostream& operator<<(ostream& os,const Stock& s){
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);
    os << "Company: " << s.company_ << "\n";
	os << "Shares: " << s.shares_ << "\n";
	os << "Share_val: " << s.shareVal_ << "\n";
    os.precision(2);
    os << "Total_val: " << s.totalVal_ << "\n";
    // set format to #.##
    os.setf(orig, ios_base::floatfield);
    os.precision(prec);

    return os;
}

#include "stonewt.h"
#include <iostream>

Stonewt::Stonewt(double lbs, Mode form){
    form_ = form;
    if(form == StnForm){
        stone_ = lbs / LbsPerStn;
        pdsLeft_ = lbs - stone_ * LbsPerStn;
        pounds_ = 0;
    }else if(form == IntPoundForm){
        stone_ = 0;
        pdsLeft_ = 0;
        pounds_ = (int)lbs;
    }else if(form == FloatPoundForm){
        stone_ = 0;
        pdsLeft_ = 0;
        pounds_ = lbs;
    }else{
        std::cout << "wrong form" << std::endl;
    }
}

Stonewt::Stonewt(int stn, double lbs, Mode form){
    form_ = form;
    if(form == StnForm){
        stone_ = stn;
        pdsLeft_ = lbs;
        pounds_ = 0;
    }else if(form == IntPoundForm){
        stone_ = 0;
        pdsLeft_ = 0;
        pounds_ = (int)(stn * LbsPerStn + lbs);
    }else if(form == FloatPoundForm){
        stone_ = 0;
        pdsLeft_ = 0;
        pounds_ = stn * LbsPerStn + lbs;
    }else{
        std::cout << "wrong form" << std::endl;
    }
}

void Stonewt::Calculate(){
    if(form_ == StnForm){
        pounds_ = stone_ * LbsPerStn + pdsLeft_;
    }else if(form_ == IntPoundForm){
        stone_ = pounds_ / LbsPerStn;
        pdsLeft_ = (int)(pounds_ - stone_ * LbsPerStn);
    }else if(form_ == FloatPoundForm){
        stone_ = pounds_ / LbsPerStn;
        pdsLeft_ = pounds_ - stone_ * LbsPerStn;
    }else{
        std::cout << "wrong form" << std::endl;
    }
}

/* 
   以下写法属于简单问题复杂化，存在的意义是为了显示报错的原因
   error: passing ‘const xxx’ as ‘this’ argument discards qualifiers [-fpermissive]
   与11-4中的一起看（见笔记）
   最好的解决方式是在i构造函数中stone_/pdsLeft_/pounds_一起算了
 */
Stonewt Stonewt::operator+(const Stonewt& another) const{
    Stonewt temp = *this;
    Stonewt temp2 = another;
    temp.Calculate();
    temp2.Calculate();
    temp.pounds_ += temp2.pounds_;
    temp.stone_ = temp.pounds_ / Stonewt::LbsPerStn;
    temp.pdsLeft_ = temp.pounds_ - temp.stone_ * Stonewt::LbsPerStn;
    return temp;
}

Stonewt Stonewt::operator-(const Stonewt& another) const{
    Stonewt temp = *this;
    Stonewt temp2 = another;
    temp.Calculate();
    temp2.Calculate();
    temp.pounds_ -= temp2.pounds_;
    temp.stone_ = temp.pounds_ / Stonewt::LbsPerStn;
    temp.pdsLeft_ = temp.pounds_ - temp.stone_ * Stonewt::LbsPerStn;
    return temp;
}
Stonewt Stonewt::operator*(double n) const{
    Stonewt temp = *this;
    temp.Calculate();
    temp.pounds_ *= n;
    temp.stone_ = temp.pounds_ / Stonewt::LbsPerStn;
    temp.pdsLeft_ = temp.pounds_ - temp.stone_ * Stonewt::LbsPerStn;
    return temp;
}

bool Stonewt::operator>(const Stonewt& another) const{
    Stonewt temp2 = *this;
    Stonewt temp = another;
    temp2.Calculate();
    temp.Calculate();
    if(temp2.pounds_ > temp.pounds_){
        return true;
    }
    return false;
}

bool Stonewt::operator<(const Stonewt& another) const{
    Stonewt temp2 = *this;
    Stonewt temp = another;
    temp2.Calculate();
    temp.Calculate();
    if(temp2.pounds_ < temp.pounds_){
        return true;
    }
    return false;
}

bool Stonewt::operator==(const Stonewt& another) const{
    Stonewt temp2 = another;
    temp2.Calculate();
    if(this->pounds_ == temp2.pounds_){
        return true;
    }
    return false;   
}
/* 
   以上写法属于简单问题复杂化，存在的意义是为了显示报错的原因
   error: passing ‘const xxx’ as ‘this’ argument discards qualifiers [-fpermissive]
   与11-4中的一起看（见笔记）
   最好的解决方式是在i构造函数中stone_/pdsLeft_/pounds_一起算了
 */

std::ostream& operator<<(std::ostream& os, const Stonewt& singStn){
    if(singStn.form_ == singStn.StnForm){
        os << "stone_:" << singStn.stone_ << ". pdsLeft_:" << singStn.pdsLeft_ <<
            ". pounds_:" << singStn.pounds_ << ". form_:" << singStn.form_;
    }else if(singStn.form_ == singStn.IntPoundForm){
        os << ". pounds_:" << (int)singStn.pounds_ << ". form_:" << singStn.form_;
    }else if(singStn.form_ == singStn.FloatPoundForm){
        os << ". pounds_:" << singStn.pounds_<< ". form_:" << singStn.form_;
    }
    return os;
}

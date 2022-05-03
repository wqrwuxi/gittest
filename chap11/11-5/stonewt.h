#ifndef STONEWT_H_
#define STONEWT_H_
#include <ostream>
class Stonewt{
private:
    enum Mode{
        StnForm,
        IntPoundForm,
        FloatPoundForm
    };

public:
    Stonewt() : stone_(0), pdsLeft_(0.), pounds_(0.), form_(StnForm) {}
    // Stonewt(double lbs, Mode form = StnForm);
    // Stonewt(int stn, double lbs, Mode form = StnForm);
    Stonewt(double lbs, Mode form = StnForm);
    Stonewt(int stn, double lbs, Mode form = StnForm);
    virtual ~Stonewt() {}
    void Calculate();
    Mode Stn() {return StnForm;}
    Mode IntPound() {return IntPoundForm;}
    Mode FloatPound() {return FloatPoundForm;}
    double GetPound() {return pounds_;}
    Stonewt operator+(const Stonewt& another) const;
    Stonewt operator-(const Stonewt& another) const;
    Stonewt operator*(double n) const;
    bool operator>(const Stonewt& another) const;
    bool operator<(const Stonewt& another) const;
    bool operator>=(const Stonewt& another) const {return !operator<(another);}
    bool operator<=(const Stonewt& another) const {return !operator>(another);}
    bool operator==(const Stonewt& another) const;
    bool operator!=(const Stonewt& another) const {return !operator==(another);}
    friend Stonewt operator*(double n, const Stonewt& singleStn) {return singleStn * n;}
    friend std::ostream& operator<<(std::ostream& os, const Stonewt& singleStn);
private:
    enum {LbsPerStn = 14};
    //static const int LbsPerStn = 14;
    // enum Mode{
    //     StnForm,
    //     IntPoundForm,
    //     FloatPoundForm
    // };
    int stone_;
    double pdsLeft_;
    double pounds_;
    Mode form_;
};

std::ostream& operator<<(std::ostream& os, const Stonewt& singStn);

#endif /* STONEWT_H_ */
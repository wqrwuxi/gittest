#pragma once
#ifndef STONEWT_H_
#define STONEWT_H_
#include<iostream>

class Stonewt
{
private:
	//enum class Mode{Stn_Form,Int_Pounds_Form,Float_Pounds_Form};
	enum Mode{Stn_Form,Int_Pounds_Form,Float_Pounds_Form};
	static const int Lbs_Per_Stn = 14;
	int stone;
	double pds_left;
	double pounds;
	Mode Form;
public:
	Stonewt(double lbs, Mode form = Stn_Form);
	Stonewt(int stn, double lbs, Mode form = Stn_Form);
	Stonewt();
	~Stonewt() {};
	void StnForm() { Form = Stn_Form; }
	void IntPoundsForm(){ Form = Int_Pounds_Form; }
	void FloatPoundsForm() { Form = Float_Pounds_Form; }
	//void showStone() { std::cout << this->stone<<"\n"; }
	//void showPds_Left(){ std::cout << this->pds_left<<"\n"; }
	//void showPounds() { std::cout << this->pounds<<"\n"; }
	Stonewt operator+(const Stonewt&)const;
	Stonewt operator-(const Stonewt&)const;
	Stonewt operator*(double n);
	friend std::ostream& operator<<(std::ostream&, const Stonewt&);
};
#endif // !STONEWT_H_
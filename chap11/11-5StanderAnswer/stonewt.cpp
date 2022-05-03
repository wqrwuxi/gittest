#include<iostream>
#include "stonewt.h"

Stonewt::Stonewt(double lbs, Mode form)
{
	if (form == Int_Pounds_Form)
	{
		Form = Int_Pounds_Form;
		pounds = int(lbs);
		stone = 0;
		pds_left = 0;
	}
	else if (form == Float_Pounds_Form)
	{
		Form = Float_Pounds_Form;
		pounds = lbs;
		stone = 0;
		pds_left = 0;
	}
	else if(form==Stn_Form)
	{
		Form = Stn_Form;
		stone = int(lbs) / Lbs_Per_Stn;
		pds_left = int(lbs) % Lbs_Per_Stn + lbs - int(lbs);
		pounds = 0;
	}
}
Stonewt::Stonewt(int stn, double lbs, Mode form)
{
	if (form == Stn_Form)
	{
		Form = Stn_Form;
		stone = (stn*Lbs_Per_Stn+lbs)/Lbs_Per_Stn;
		pds_left =int(stn*Lbs_Per_Stn + lbs) % Lbs_Per_Stn;
		pounds = 0;
	}
	else if (form == Float_Pounds_Form)
	{
		Form = Mode::Float_Pounds_Form;
		pounds = stn*Lbs_Per_Stn + lbs;
		stone = 0;
		pds_left = 0;
	}
	else if(form==Int_Pounds_Form)
	{
		Form = Mode::Int_Pounds_Form;
		pounds = int(stn*Lbs_Per_Stn + lbs);
		stone = 0;
		pds_left = 0;
	}
}
Stonewt::Stonewt()
{
	stone = pds_left = pounds = 0;
}
Stonewt Stonewt::operator+(const Stonewt& stn)const
{
	Stonewt st;
	if (Form == Stn_Form)
	{
		st.stone = this->stone + stn.stone;
		st.pds_left = this->pds_left + stn.pds_left;
		st.stone += st.pds_left / Lbs_Per_Stn;
		st.pds_left = int(st.pds_left) % Lbs_Per_Stn;
		//std::cout << "st.stone: " << st.stone << ", " << "st.pds_left: " << st.pds_left << std::endl;
	}
	else if (Form == Int_Pounds_Form)
		st.pounds = this->pounds + stn.pounds;
	else if(Form==Mode::Float_Pounds_Form)
		st.pounds = this->pounds + stn.pounds;
	return st;
}
Stonewt Stonewt::operator-(const Stonewt& stn)const
{
	Stonewt st;
	if (Form == Stn_Form)
	{
		st.stone = this->stone - stn.stone;
		st.pds_left = this->pds_left - stn.pds_left;
		st.stone += st.pds_left / Lbs_Per_Stn;
		st.pds_left = int(st.pds_left) % Lbs_Per_Stn;
	}
	else if (Form == Int_Pounds_Form)
		st.pounds = int(this->pounds - stn.pounds);
	else if (Form == Float_Pounds_Form)
		st.pounds = this->pounds - stn.pounds;
	return st;
}
Stonewt Stonewt::operator*(double n)
{
	Stonewt st;
	if (Form == Stn_Form)
	{
		st.stone = this->stone*n;
		st.pds_left = this->pds_left*n;
		st.stone += st.pds_left / Lbs_Per_Stn;
		st.pds_left = int(st.pds_left) % Lbs_Per_Stn;
		//std::cout << "st.stone: " << st.stone << ", " << "st.pds_left: " << st.pds_left << std::endl;
	}
	else if (Form == Int_Pounds_Form)
		st.pounds = int(this->pounds*n);
	else if (Form == Float_Pounds_Form)
		st.pounds = this->pounds*n;
	return st;
}
std::ostream& operator<<(std::ostream& os, const Stonewt& st)
{
	if (st.Form == Stonewt::Stn_Form)
		os << st.stone << " stone, " << st.pds_left << " pounds.\n";
	else if (st.Form == Stonewt::Int_Pounds_Form)
		os << st.pounds << " pounds.\n";
	else if (st.Form == Stonewt::Float_Pounds_Form)
		os << st.pounds << " pounds.\n";
	return os;
}
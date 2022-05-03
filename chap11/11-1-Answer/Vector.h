#pragma once
#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POL };
		//RECT for Rectangular, POL for Polar modes
	private:
		double x, y;
		double mag, ang;
		Mode mode;
		//Private methods for setting values
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		~Vector(){}
		void reset(double n1, double n2, Mode form = RECT);
		double xval()const { return x; }
		double yval()const { return y; }
		double magval()const { return mag; }
		double angval()const { return ang; }
		void polar_mode();
		void rect_mode();
		//Operator overloading
		Vector operator+(const Vector&)const;
		Vector operator-(const Vector&)const;
		Vector operator-()const;
		Vector operator*(double)const;
		//Friend functions
		friend Vector operator*(double, const Vector&);
		friend std::ostream& operator<<(std::ostream&, const Vector&);
	};
}
#endif // !VECTOR_H_
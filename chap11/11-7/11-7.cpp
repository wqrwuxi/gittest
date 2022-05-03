#include "complex0.h"
#include <iostream>
int main(){
    using std::cout;
    using std::cin;
    using std::endl;
    Complex a(3., 4.);
	Complex c;
    Complex d;
	cout << "Enter a complex number (q to quit): ";
	while (cin >> c)
	{
		cout << "c is " << c << "\n";
		cout << "complex conjugate is " << ~c << "\n";
		cout << "a is " << a << "\n";
		cout << "a+c is" << a + c << "\n";
		cout << "a-c is" << a - c << "\n";
		cout << "a*c is" << a*c << "\n";
		//cout << "a/c is" << a / c << "\n";
		cout << "2*c is" << c * 2 << "\n";
        d = a;
        cout << "d is " << d << "\n";
		cout << "Enter a complex number (q to quit): ";
	}
	std::cout << "Bye" << std::endl;
}
#include<fstream> 
#include<cstdlib>
#include<ctime>
#include <cmath>
#include"Vector.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0., 0.);
	unsigned  long steps = 0;
	double target;
	double dstep;
	ofstream fout("E:\\RandomWalker.txt");
	if (!fout.is_open()) { cout << "Error opening file"; exit(1); }
	else if (fout.good()) { cout << "The file is good"; }
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))break;
		fout << "Target distance: " << target << ", step size: " << dstep << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			//result.polar_mode();
			step.reset(dstep*cos(direction), dstep*sin(direction), Vector::RECT);
				result = step + result;
				fout << result << endl;
			steps++;
		}
		fout << "After " << steps << " steps, the subject has the following location: \n";
		fout << result << endl;
		result.polar_mode();
		fout << "or \n" << result << endl;
		fout << "Average outward distance per step = " << result.magval() / steps << endl;
		/*=====================================================*/
		result.rect_mode();
		cout << "After " << steps << " steps, the subject has the following location: \n";
		cout << result << endl;
		result.polar_mode();
		cout << "or \n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0., 0.);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	fout.close();
	system("pause");
	return 0; 
}
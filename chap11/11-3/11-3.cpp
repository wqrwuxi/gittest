#include "walk.h"

#include <cstdlib>// Header file needed to use rand
#include <ctime> // Header file needed to use time
#include <fstream>
#include <iostream>
#include <vector>
#include <numeric>//accumulate
#include <algorithm>//max_element min_element

int main(){
    using namespace std;
	using Vector::Vector;
    Vector step;
    Vector result;
    double nowLen;
    double lenStep;
    double angle;

    srand(time(0));

    ofstream fout("result.txt");
    // ofstream fout;
    // fout.open("result.txt", ios::out, 0);
    if(!fout.is_open()){
        cout << "open result.txt failed" << endl;
    }

    double target;
    double stepLen;
    double angles;
    int count = 0;
    vector<unsigned long> num;
    cout << "Enter target distance (q to quit): ";//q怎么显示    
    while(cin >> target){
        cout << "Enter step length: ";
        cin >> stepLen;
        fout << "target distance" << target << ". step length:" << stepLen << endl;
        while(result.GetR() < target){
            angles = rand() % 360;
            step.Step(stepLen, angles, Vector::POL);
            /* 在枚举值是 enum Mode{POL，RECT};时，一调用下面的+式子，就跳成POL模式
               原因：枚举值，默认是第一个值。+式调用了Vector的构造函数，Vector::Vector(double num1, double num2, Mode form)
               这个构造函数当时没有写mode_ = form，所以调用了默认枚举值：POL
            */
            result = step + result;
            count++;
        }
        fout << count << endl;
        num.push_back(count);
        result.Step(0, 0, Vector::RECT);
        count = 0;
        cout << "Enter target distance (q to quit): ";
    }
    fout.close();
    unsigned long sum = accumulate(begin(num), end(num), 0);
    unsigned long average = sum / num.size();
    unsigned long max = *max_element(num.begin(), num.end());
    unsigned long min = *min_element(num.begin(), num.end());
    cout << "average:" << average << ". max:" << max << ". min:" << min << endl;
}
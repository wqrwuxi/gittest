#include "stonewt.h"
#include <iostream>
#include <vector>
#include <algorithm>//sort函数

int main(){
    Stonewt taft(21, 8);
	Stonewt cat(19.6, 10.1, cat.IntPound());
    Stonewt cat2(19.6, 10.1, cat2.FloatPound());
	std::cout <<"taft: "<< taft << std::endl;
	std::cout << "cat: " << cat << std::endl;
    std::cout << "cat2: " << cat2 << std::endl;
    std::cout <<"taft * 2: "<< taft*2 << std::endl;
    std::cout <<"taft - cat2: "<< taft - cat2 << std::endl;
    std::cout <<"taft + cat: "<< taft + cat << std::endl;
    std::cout <<"taft > cat ? : "<< (taft > cat) << std::endl;
    std::cout <<"taft <= cat ? : "<< (taft <= cat) << std::endl;
    std::cout <<"taft != cat ? : "<< (taft != cat) << std::endl;

    Stonewt* pStonewt = new Stonewt[6];
    std::vector<double> arr;
    pStonewt[0] = Stonewt(20, 3);
	pStonewt[1] = Stonewt(21, 4);
	pStonewt[2] = Stonewt(11, 0);
    std::cout <<"Initialize the remainders.\n";
    for(int i=3; i < 6; i++){
        int stn;
		double lbs;
		std::cout << "Enter the stone: ";
		std::cin >> stn;
		std::cout << "Enter the lbs: ";
		std::cin >> lbs;
		pStonewt[i] = Stonewt(stn, lbs);
    }

    for(int i=0; i < 6; i++){
        pStonewt[i].Calculate();
        arr.push_back(pStonewt[i].GetPound());
    }

    sort(arr.begin(), arr.end(), [](double &a, double &b){
        return a>b;
    });

    for(auto &i : arr){
        std::cout << i << "  ";
    } 



}
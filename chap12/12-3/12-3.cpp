#include "stock.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    const int STKS = 4;
	Stock Stocks[STKS] = {Stock("Nano Smart",12,20.0),
		Stock("Boffo Objects",200,2.0),
		Stock("Monolithics Obelisks",130,3.25),
		Stock("Fleep Enterprises",60,6.5),
	};
	cout << "Stocks holding: \n";
	int st;
	for (st = 0; st < STKS; st++)
		std::cout << Stocks[st];
	const Stock* top = &Stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->Topval(Stocks[st]);
	cout << "Most valuable holding: \n";
	cout << *top << "\n";
}
#include "mytime.h"
#include <iostream>

int main(){
    using std::cout;
    using std::endl;
    MyTime aida(3,35);
    MyTime tosca(2,48);
    MyTime temp;

    cout << "aida:" << aida << "tosca:" << tosca;
    temp = aida + tosca;
    cout << "aida + tosca:" << temp;
    temp = aida - tosca;
    cout << "aida - tosca:" << temp;
    temp = aida * 1.17;
    cout << "aida *1.17:" << temp;
    cout << "10 * tosca:" << tosca*10;
}
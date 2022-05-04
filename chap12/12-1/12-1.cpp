#include "cow.h"

int main(){
    Cow c1;
    //c1.ShowCow();
    Cow c2("wang", "play", 50);
    c2.ShowCow();
    Cow c3 = c2;
    c3.ShowCow();
    Cow* c4 = new Cow("ww" , "play", 60.1);
    c4->ShowCow();
    Cow* c5 = new Cow; 
    //c5->ShowCow();
    Cow c6 = Cow(c2);
    c6.ShowCow();
    *c5 = c2;
    c5->ShowCow();
    c1 = c2;
    c1.ShowCow();
    delete c4;
    delete c5;
}
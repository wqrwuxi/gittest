#include <stdio.h>

int add(int x, int y) {
    int sum=0;

    for(int i=0;i<5;i++)
    {
       sum+=(x+y+i);
    }

    return sum;
}

int main()
{
    int a=1;
    int b=2;

    for(int i=0;i<5;i++)
    {
        b+=i;
    }

    int c = add(a, b) ;
    printf("c   :%d\n",c);
    
   return 0;

}
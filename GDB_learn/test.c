#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int main() {
    int a = 1;
    int b = 2;
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    int c = add(a, b);
    printf("%d + %d = %d\n", a, b, c);
    return 0;
}

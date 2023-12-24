#include <stdio.h>

int func4(int a, int b, int c);

int main() {
    int x, y;
    printf("Enter values for x and y: ");
    scanf("%d %d", &x, &y);

    int result = func4(y, x, 0);
    printf("func4(%d, %d) returns %d\n", x, y, result);

    return 0;
}

int func4(int a, int b, int c) {
    int val=14; //rax
    b=11; // rdi
    a=0; // rsi

    val-a;
    int val1=val; //rbx
    val1>>=31;
    val1+=val;
    val1>>1;
    val1+a;

    if(val1>b){

    }
}

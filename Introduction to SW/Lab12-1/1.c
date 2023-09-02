#include <stdio.h>

const double pi=3.141592;
#define SQUARE(x) ((x)*(x));

int main(){
    double num;
    scanf("%lf",&num);
    double peri=2*pi*num;
    double rad=pi*SQUARE(num);
    printf("perimeter: %.6f\n",peri);
    printf("Area: %.6f\n",rad);
    return 0;
}
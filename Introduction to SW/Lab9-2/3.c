#include <stdio.h>

int main(){
    double num[5];
    double* parr=num;
    double sum=0;

    for(int i=0;i<5;i++){
        scanf("%lf",&num[i]);
        printf("%lf\n",2*num[i]);
        sum+=2*num[i];
    }
    printf("sum: %lf\n",sum);
    return 0;
}
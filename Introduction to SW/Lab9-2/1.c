#include <stdio.h>

int main(){
    int num[5];
    int i;
    int sum=0;
    int max=num[0];
    int min=num[0];
    
    for(i=0;i<5;i++){
        scanf("%d",&num[i]);
    }
    for(i=0;i<5;i++){
        if(num[i]<min)
            min=num[i];
        if(num[i]>max)
            max=num[i];
        sum+=num[i];
    }
    printf("min: %d\n",min);
    printf("max: %d\n",max);
    printf("sum: %d\n",sum);
    //printf(min d\nmax d\nsum d\n”, min, max, sum);
    return 0;
}
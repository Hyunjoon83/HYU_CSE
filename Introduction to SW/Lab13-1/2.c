#include <stdio.h>
#include <stdlib.h>

void MinMax(int n){
    int* pNum=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&pNum[i]);
    }
    int min=pNum[0];
    int max=pNum[0];    
    
    for(int i=1;i<n;i++){
        if(pNum[i]<min){    
            min=pNum[i];
        }else if(pNum[i]>max){
            max=pNum[i];
        }
    }
    printf("min: %d\n",min);
    printf("max: %d\n",max);
    free(pNum);
}
int main(){
    int num;
    scanf("%d",&num);
    MinMax(num);
    return 0;
}
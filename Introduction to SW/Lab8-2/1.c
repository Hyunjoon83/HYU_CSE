#include <stdio.h>

int printLine(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    for(int i=n;i>0;i--){
        for(int j=1;j<=i;j++){
          printf("%d ",j);
        }
        printf("\n");
    }
}
int main(){
    int num;
    scanf("%d",&num);
    printLine(num);
    return 0;
}
#include <stdio.h>

int main(){
    char k,n;
    while(1){
        scanf("%c%c",&k,&n);
        if(k>=65 && k<=90){
            printf("-> %c\n",k+32);
        }else if(k>=97 && k<=122){
            printf("-> %c\n",k-32);
        }else if(k>=48 && k<=57){
            printf("-> %c\n",k);
        }else{
            printf("exit\n");  
            break;
        }
    }
    return 0;
}
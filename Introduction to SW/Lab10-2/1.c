#include <stdio.h>
#include <string.h>

int main(){
    char str[9];
    scanf("%s",str);
    int n=strlen(str);
    int isPalin=1;

    if(n>=10){
        return 0;
    }
    for(int i=0;i<n;i++){
        if(str[i]!=str[n-i-1]){
            isPalin=0;
            break;
        }
    }
    if(isPalin==0){
        printf("This is not a palindrome\n");
    }else{
        printf("This is a palindrome\n");
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[10];
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++) {
        if (!isalpha(str[i])) {
            return 1;
        }
    }
    for(int i=0;i<strlen(str);i++)
        if(islower(str[i])){
            printf("%c",toupper(str[i]));
        }else{
            printf("%c",tolower(str[i]));
        }
    printf("\n");
    return 0;
}
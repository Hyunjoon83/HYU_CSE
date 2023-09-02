#include <stdio.h>
#include <string.h>

int main(){
    char char1[10];
    char char2[10];
    char str1[10];
    char str2[10];
    
    scanf("%s",char1);
    scanf("%s",char2);

    strcpy(str1,char1);
    strcpy(str2,char2);

    printf("str1: %s\n",str1);
    printf("str2: %s\n",str2);

    int len1=strlen(str1);
    int len2=strlen(str2);
    printf("length of str1: %d\n",len1);
    printf("length of str2: %d\n",len2);
    printf("str1+str2: %s\n",strcat(char1,char2));
    
    if(strcmp(str1,str2)==0){
        printf("same\n");
    }else{
        printf("not same\n");
    }
    return 0;
}
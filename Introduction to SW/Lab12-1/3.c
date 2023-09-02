#include <stdio.h>

void printString(const char* str){
    const char* arr[3]={"One","Two","Three"};
    for(int i=0;i<3;i++)
        printf("%s\n",arr[i]);
}
int main(){
    char* str;
    printString(str);
    return 0;
}

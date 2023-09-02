#include <stdio.h>
#include <stdlib.h>

void swap(char** pstr1,char** pstr2){
    char* temp=*pstr1;
    *pstr1=*pstr2;
    *pstr2=temp;
}
void printArray(char** arr){
    printf("Array [0]:%s, [1]:%s,\n",arr[0],arr[1]);
}
int main(){
    char* arr[2]={"aaa","bbb"};
    printArray(arr);
    swap(&arr[0],&arr[1]);
    printArray(arr);
    return 0;
}
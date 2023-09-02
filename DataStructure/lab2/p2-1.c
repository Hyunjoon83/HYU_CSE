#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int n=argv[1][0]-'0';
    int i;
    char** arr=(char**)malloc(sizeof(char)*31*n);
    char* str;

    fprintf(stdout,"enter %d names:\n",n);

    for(i=0;i<n;i++){
        str=(char*)malloc(sizeof(char)*31);
        fscanf(stdin,"%s",str);
        arr[i]=str;
    }
    fputs("the names you entered:\n",stdout);
    for(i=0;i<n;i++){
        fprintf(stdout,"%s\n",arr[i]);
    }
    free(arr);
    return 0;
}
/* 1. argc 및 argv 인자를 사용하여 입력된 명령행 인자를 읽음
   2. 문자열 배열 arr을 동적으로 할당 (할당 된 배열의 크기 = 31바이트 * 문자열의 개수)
   3. for 루프를 사용하여 문자열을 입력 받고, 입력 된 문자열을 동적으로 할당 된 배열에 저장
        -fscanf 함수를 사용하여 새로운 문자열을 입력 받음
        -입력 된 문자열은 str에 저장되며, arr배열의 i번째 요소에 할당
   4. 배열에 입력 된 모든 문자열을 출력
        -for 루프를 사용하여 배열의 모든 요소를 출력
        -fprintf 함수를 사용하여 각 요소를 출력
*/
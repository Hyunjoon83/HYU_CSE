#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 31

typedef struct Student
{
    char name[MAX_LEN];
    int student_id;
    char major[MAX_LEN];
}Student;

int main(int argc, char** args){
    char *input_path, *output_path;
    FILE *fi, *fo;

    int n;
    int i;

    input_path = args[1];
    output_path = args[2];

    fi = fopen(input_path, "r");
    fo = fopen(output_path,"w");
    fscanf(fi,"%d", &n);
    Student* students;
    students = malloc(sizeof(Student) * n);
    
    for (i = 0; i < n; i++) {
        fscanf(fi, "%s %d %s", students[i].name, &students[i].student_id, students[i].major);
    }
    for (i = 0; i < n; i++) {
        fprintf(fo, "%-15s %-11d %-30s\n", students[i].name, students[i].student_id, students[i].major);
    }

	fclose(fi);
    fclose(fo);
    free(students);

    return 0;

}
/* 1. argc 및 argv 인자를 사용하여 입력된 명령행 인자를 읽음
        -두 번째 인자 = 출력 파일의 경로
   2. 입력 및 출력 파일의 파일 포인터를 열음
        -fopen 함수를 사용하여 파일을 열음
        -입력 파일에서는 총 학생 수를 나타내는 정수 n을 읽어옴
   3. 학생 정보를 저장하기 위한 구조체 배열 students를 malloc 함수를 이용하여 동적으로 할당
   4. for 루프를 사용하여 학생 정보를 입력 받고, 배열에 저장
        -fscanf 함수를 사용하여 각 학생의 정보를 입력 받음
        -각 학생의 정보는 students배열의 i번째 요소에 저장
   5. for 루프를 사용하여 배열에 저장된 모든 학생 정보를 출력 파일에 쓰기 위해 사용
        -fprintf 함수를 사용하여 각 학생의 정보를 출력
        -출력 형식은 "이름(ID) 전공"
        -출력 파일의 경로는 입력 인자로 받아들인 두 번째 인자
   6. 입력 파일과 출력 파일의 파일 포인터를 fclose함수를 이용하여 닫음
*/
#include <stdio.h>
#include <string.h>

struct Info{
    char name[10];
    int age;
};
typedef struct Info info;
int main(){
    info person;
    scanf("%s %d",person.name,&person.age);
    printf("name: %s\n",person.name);
    printf("age: %d\n",person.age);
    return 0;
}
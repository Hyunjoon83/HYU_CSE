#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 10

typedef struct StackRecord *Stack;

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    int *Array;
};

Stack CreateStack(int maxElements) {
    Stack S = (Stack)malloc(sizeof(struct StackRecord));//StackRecord만큼의 크기를 가지는 스택을 위한 메모리를 할당
    if (S == NULL) {
        printf("Out of space!!!");
        exit(1);
    }//만약 메모리 할당이 실패하면, "Out of space!!!" 메시지를 출력하고 프로그램을 종료
    S->Array = malloc(sizeof(int) * maxElements);//maxElements만큼의 크기를 가지는 배열을 위한 메모리를 할당
    if (S->Array == NULL) {
        printf("Out of space!!!");
        exit(1);
    }//만약 메모리 할당이 실패하면, "Out of space!!!" 메시지를 출력하고 프로그램을 종료
    S->Capacity=maxElements;//스택의 용량을 maxElements로 설정
    S->TopOfStack = -1;//스택의 탑 인덱스를 -1로 초기화
    return S;//생성된 스택을 반환
}//동적으로 할당된 배열과 스택 포인터를 초기화하여 스택을 생성하고, 생성된 스택 포인터를 반환합니다. 메모리 할당이 실패한 경우 프로그램을 종료
int IsEmpty(Stack S){
    return S -> TopOfStack == -1;
}
/*스택이 비어있는지 확인
S->TopOfStack 값이 -1이면, 스택이 비어있는 것으로 판단하고 1을 반환, 비어있지 않으면 0을 반환
*/
int IsFull(Stack S){
    return S -> TopOfStack == S->Capacity -1;
}
/*스택이 가득 차 있는지 확인
S->TopOfStack 값이 S->Capacity - 1과 같으면, 스택이 가득 차있는 것으로 판단하고 1을 반환, 가득 차 있지 않으면 0을 반환
*/
void Push(int x, Stack S){
    if(IsFull(S)){
        printf("Stack is Full");
        return;
    }
    S->Array[++S->TopOfStack] = x;
}
/*스택에 x 값을 push
IsFull(S) 함수를 사용하여 스택이 가득 차 있는지 확인하고, 가득 차 있다면 "Stack is Full" 메시지를 출력하고 함수를 종료합니다.
가득 차 있지 않다면, S->Array 배열의 ++S->TopOfStack 인덱스에 x 값을 할당
*/
int Pop(Stack S) {
    if (IsEmpty(S)) {
        printf("Stack is empty");
        return -1;
    }
    return S->Array[S->TopOfStack--];
}
/*스택에서 값을 pop
IsEmpty(S) 함수를 사용하여 스택이 비어있는지 확인하고, 비어있다면 "Stack is empty" 메시지를 출력하고 -1을 반환
비어있지 않다면, S->Array 배열의 S->TopOfStack-- 인덱스의 값을 반환하고, S->TopOfStack 값을 1 감소시킴
*/
int Top(Stack S){
    if(IsEmpty(S)){
        printf("Stack is Empty");
        return -1;
    }
    return S->Array[S->TopOfStack];
}
/*스택의 top 값을 반환
IsEmpty(S) 함수를 사용하여 스택이 비어있는지 확인하고, 비어있다면 "Stack is Empty" 메시지를 출력하고 -1을 반환
비어있지 않다면, S->Array 배열의 S->TopOfStack 인덱스의 값을 반환
*/
void Postfix(Stack S, char c) {
    int x, y;
    switch (c) {
        case '+':
            y = Pop(S);
            x = Pop(S);
            Push(x+y, S);
            break;
        case '-':
            y = Pop(S);
            x = Pop(S);
            Push(x-y, S);
            break;
        case '*':
            y = Pop(S);
            x = Pop(S);
            Push(x*y, S);
            break;
        case '/':
            y = Pop(S);
            x = Pop(S);
            Push(x/y, S);
            break;
        case '%':
            y = Pop(S);
            x = Pop(S);
            Push(x%y, S);
            break;

        default:
            Push(c-'0', S);
            break;
    }
}
int main(int argc, char* argv[]){

    FILE* fi = fopen(argv[1],"r");//인자로 받은 파일명(argv[1])을 열어 파일 포인터 fi에 저장

    Stack stack=CreateStack(MAX_STACK_SIZE);//스택을 생성하고, CreateStack(MAX_STACK_SIZE)를 호출하여 초기화

    char c;//char c를 선언하여 파일에서 한 글자씩 읽어들임
    printf("Top numbers: ");
        while(fscanf(fi,"%c",&c)!=EOF){
            if(c == '#'){
                break;
            }//c가 #일 경우, while 루프를 탈출
            Postfix(stack,c);//Postfix(stack,c)를 호출하여 스택에 계산 결과를 저장
            printf("%d ",Top(stack));//현재 스택의 최상단 값(Top(stack))을 출력
        }
    printf("\n");//줄바꿈 수행
    printf("evaluation result: %d\n", Pop(stack));//스택에서 최종 결과를 pop하여 evaluation result를 출력

    fclose(fi);
    free(stack->Array);
    free(stack);

    return 0;
}//파일 포인터를 닫고, 메모리 해제를 수행
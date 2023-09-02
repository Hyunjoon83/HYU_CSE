#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueueStruct{
    int *key;
    int Front;
    int Rear;
    int Size;
    int QueueSize;
}Queue;     

typedef Queue* CircularQueue;

int Succ(int i, CircularQueue Q){
        if (i==Q->QueueSize-1){
                return 0;
        }else{
                return i+1;
        }
}
/*현재 위치 i가 큐의 끝(Q->QueueSize-1)에 도달한 경우, 다음 위치는 큐의 맨 앞(0)입니다.
그렇지 않은 경우, 다음 위치는 i+1
*/
CircularQueue MakeEmpty(int max){
        CircularQueue Q=(CircularQueue)malloc(sizeof(Queue));//크기가 max인 CircularQueue를 동적 할당
        Q->key=(int*)malloc(sizeof(int) * max);//크기가 max인 정수형 배열을 동적 할당하여 key 포인터에 저장
        Q->Front=0;//Front를 0으로 초기화
        Q->Rear=-1;//Rear를 -1로 초기화
        Q->Size=0;//Size를 0으로 초기화
        Q->QueueSize=max;//QueueSize를 max로 초기화
        return Q;//초기화된 CircularQueue를 반환

};
int IsEmpty(CircularQueue Q){
        return Q->Size==0;
};
int IsFull(CircularQueue Q){
        return Q->Size==Q->QueueSize;
}

void Dequeue(CircularQueue Q){
        if (IsEmpty(Q)){
                fprintf(stdout,"Dequeue failed: Queue is Empty!\n");
        }else{  
                fprintf(stdout,"Dequeue %d\n",Q->key[Q->Front]);
                Q->Front=Succ(Q->Front,Q);
                (Q->Size)--;
        }
}
/*IsEmpty" 함수를 호출하여 큐가 비어 있는지 확인합니다. 대기열이 비어 있으면 "Dequeue failed: Queue is Empty!"라는 메시지를 표준 출력에 인쇄
Queue가 비어 있지 않으면 Queue 맨 앞에 있는 요소를 Dequeue
"fprintf" 함수를 사용하여 큐에서 빼낸 요소의 값을 표준 출력으로 인쇄
순환 대기열의 다음 요소 인덱스를 계산하는 "Succ" 함수를 호출하여 대기열의 전면 인덱스를 업데이트합니다. 대기열의 크기도 1씩 줄어듭니다.
*/
void Enqueue(CircularQueue Q, int x){
        if (IsFull(Q))
                fprintf(stdout,"Enqueue failed: Queue is Full!\n");
        else{ 
                fprintf(stdout,"Enqueue %d\n",x);
                Q->Rear=Succ(Q->Rear,Q);
                Q->key[Q->Rear]=x;
                (Q->Size)++;
        }
}
/*IsFull" 함수를 호출하여 큐가 꽉 찼는지 확인합니다. 대기열이 가득 차면 "Enqueue failed: Queue is Full!"이라는 메시지를 표준 출력에 인쇄
큐가 가득차지 않으면 새로운 요소 "x"를 큐에 추가합니다. "fprintf" 함수를 사용하여 큐에 넣은 요소의 값을 표준 출력에 인쇄
순환 대기열에서 다음으로 사용 가능한 위치의 인덱스를 계산하는 "Succ" 함수를 호출하여 대기열의 후면 인덱스를 업데이트
배열 색인 표기법을 사용하여 대기열의 이 위치에 새 요소 "x"를 저장
대기열의 크기도 1씩 증가
*/
void PrintFirst(CircularQueue Q){
        if (IsEmpty(Q)){
                fprintf(stdout,"Queue is Empty!\n");
        }else{
                fprintf(stdout,"First: %d\n",Q->key[Q->Front]);
        }
}
/*IsEmpty" 함수를 호출하여 대기열이 비어 있는지 확인
대기열이 비어 있으면 "Queue is Empty!"라는 메시지를 표준 출력에 인쇄
대기열이 비어 있지 않으면 "fprintf" 함수를 사용하여 대기열의 첫 번째 요소 값을 표준 출력에 인쇄
*/
void PrintRear(CircularQueue Q){
        if (IsEmpty(Q)){
                fprintf(stdout,"Queue is Empty!\n");
        }else{
                fprintf(stdout,"Rear: %d\n",Q->key[Q->Rear]);
        }
}
/*IsEmpty" 함수를 호출하여 대기열이 비어 있는지 확인
대기열이 비어 있으면 "Queue is Empty!"라는 메시지를 표준 출력에 인쇄
대기열이 비어 있지 않으면 "fprintf" 함수를 사용하여 대기열의 마지막 요소 값을 표준 출력에 인쇄
*/
void DeleteQueue(CircularQueue Q){
        free(Q->key);
        free(Q);
}
/*큐 객체의 "key" 속성에 대해 "free" 함수를 호출하여 큐의 요소 배열에 할당된 메모리를 해제
큐 개체에서 "자유" 함수를 호출하여 큐 개체 자체에 할당된 메모리를 해제
*/
int main(int argc, char* argv[])
{
    char command;
    FILE *input;
    CircularQueue queue;
    int QueueSize;
    int tmpNum;

    input=fopen(argv[1],"r");
              
    while(1){
        command=fgetc(input);//문자별로 입력 파일에서 명령을 읽는 while 루프에 들어감
        if(feof(input))
                break;//입력 파일의 끝에 도달하면 "feof" 함수를 사용하여 루프가 종료
        switch(command){
            case 'n':
                    fscanf(input, "%d", &QueueSize);
                    queue=MakeEmpty(QueueSize);
                    break;
        //fscanf" 함수를 사용하여 입력 파일에서 큐의 크기를 읽고 "MakeEmpty" 함수를 사용하여 해당 크기의 빈 순환 큐를 만듦
            case 'e':
                    fscanf(input,"%d",&tmpNum);
                    Enqueue(queue,tmpNum);
                    break;
        //fscanf" 함수를 사용하여 입력 파일에서 정수 값을 읽고 "Enqueue" 함수를 사용하여 순환 큐에 넣음
            case 'd':
                    Dequeue(queue);
                    break;
        //"Dequeue" 기능을 사용하여 큐에서 요소를 제거
            case 'f':
                    PrintFirst(queue);
                    break;
        //PrintFirst" 함수를 사용하여 대기열의 첫 번째 요소 값을 표준 출력에 인쇄
            case 'r':
                    PrintRear(queue);
                    break;
        //"PrintRear" 기능을 사용하여 대기열의 마지막 요소 값을 표준 출력에 인쇄
            default:
                    break;
        }
    }
    DeleteQueue(queue);//순환 대기열 개체에 대한 메모리 할당을 해제

    return 0;//프로그램의 성공적인 완료를 나타내기 위해 0을 반환
}
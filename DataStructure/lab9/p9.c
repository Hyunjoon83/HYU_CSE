#include <stdio.h>
#include <stdlib.h>

typedef struct Heap* Heap;
struct Heap{
    int capacity;
    int size;
    int *Elements;
};

Heap CreateHeap(int HeapSize){
    Heap heap=malloc(sizeof(struct Heap));
    if(heap==NULL){
        return NULL;
    }
    heap->size=0;
    heap->capacity=HeapSize;
    heap->Elements = malloc(sizeof(int) * (HeapSize+1));
    if(heap->Elements==NULL){
        free(heap);
        return NULL;
    }//heap에 ELement가 없으면 동적할당한 heap을 해제하고 NULL 반환
    return heap;
}
int isEmpty(Heap heap){
    return heap->size=0;
}
int isFull(Heap heap){
    return heap->size==heap->capacity;
}
int Find(Heap heap, int value){
    for(int i=1;i<=heap->size;i++){
        if(heap->Elements[i]==value){
            return 1;
        }
    }//heap의 size만큼 배열을 돌면서 heap의 Element와 찾고자 하는 value의 값이 같으면 1(value)을 반환 
    return 0;
}
void Insert(Heap heap, int value){
    int i;
    if(isFull(heap)){
        printf("Insertion Error: Max Heap is full.\n");
        return;//heap이 가득 차 있으면 오류문을 출력하고 insert를 중단
    }else if(Find(heap,value)){
        fprintf(stdout,"%d is already in the heap.\n",value);
        return;//heap에서 동일한 value를 찾은 경우 오류문을 출력하고 insert 중단 
    }else{
        for(i=++heap->size;heap->Elements[i/2]<value;i/=2){
            if(i/2==0)
                break;
            heap->Elements[i]=heap->Elements[i/2];
        }//size를 늘려가면서 부모노드의 Element가 value보다 작을 때까지 부모 노드 방향으로 탐색하다가 i/2가 0일때 멈추고,
        //i(자식노드)가 가리키는 값을 i/2(부모노드)가 가리키는 값과 변경 
        heap->Elements[i]=value;//heap의 Element에 value를 할당
        printf("Insert %d\n",value);//value를 insert한 것을 출력
    }
}
void DeleteMax(Heap heap){
    if(isEmpty(heap)){
        printf("Deletion Error: Max Heap is empty!\n");
        return;
    }//heap이 비어있으면 오류문을 출력하고 DeleteMax 중단
    int maxElement=heap->Elements[1];//maxElement를 1번 index가 가리키는 값으로 설정
    int lastElement=heap->Elements[heap->size--];//heap의 마지막 요소를 lastElement 변수에 저장하고, size를 1만큼 감소
    heap->Elements[1]=lastElement;//힙의 최대값을 삭제한 후, 힙의 루트 노드에 lastElement를 저장. 이를 통해 힙의 구조를 유지하면서 최대값을 삭제할 수 있다.
    int i=1;
    while(i*2<=heap->size){
        int leftChild=(i*2);
        int rightChild=(i*2)+1;
        int maxChild=leftChild;
        if(rightChild<=heap->size&&heap->Elements[rightChild]>heap->Elements[maxChild]){
            maxChild=rightChild;
        }//rightChild가 size보다 작거나 같고, rightChild가 가리키는 Element가 maxChild가 가리키는 Element보다 크면 maxChild를 rightChild에 할당
        if(heap->Elements[i]<heap->Elements[maxChild]){
            int temp=heap->Elements[i];
            heap->Elements[i]=heap->Elements[maxChild];
            heap->Elements[maxChild]=temp;
            i=maxChild;
        }//현재 Element보다 macChild의 Element값이 작으면 tmp를 활용하여 현재 Element와 maxChild의 Element를 교환
        else{
            break;
        }
    }
    printf("Max element(%d) deleted.\n",maxElement);//delete한 maxElement값 출력
}
void PrintHeap(Heap heap){
    if(isEmpty(heap)){
        printf("Max Heap is empty!\n");
        return;
    }//heap이 비어있으면 출력문을 출력
    for(int i=1;i<=heap->size;i++) {
        printf("%d ", heap->Elements[i]);
    }//heap 내부를 돌면서 heap에 있는 Element를 출력
    printf("\n");
}
void FreeHeap(Heap heap){
    if(heap==NULL){
        return;
    }
    free(heap->Elements);
    free(heap);
}//동적할당한 녀석들을 해제
int main(int argc, char*argv[]){
    FILE *fi=fopen(argv[1],"r");
    char cv;
    Heap maxHeap=NULL;
    int value,maxValue;

    while(fscanf(fi,"%c",&cv)!=EOF){
        switch(cv){
        case 'n':
            fscanf(fi,"%d",&value);
            maxHeap=CreateHeap(value);
            break;
        case 'i':
            fscanf(fi,"%d",&value);
            Insert(maxHeap,value);
            break;
        case 'd':
            DeleteMax(maxHeap);
            break;
        case 'f':
            fscanf(fi,"%d",&value);
            if(Find(maxHeap,value))
                printf("%d is in the Heap.\n",value);
            else
                printf("%d is not in the Heap.\n",value);
            break;
        case 'p':
            PrintHeap(maxHeap);
        }
    }   
    FreeHeap(maxHeap);
    return 0;
}
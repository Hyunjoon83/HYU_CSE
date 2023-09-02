#include <stdio.h>
#include <stdlib.h>

struct MergeSort{
    int capacity;
    int size;
    int *array;
    int *tmparray;
};

typedef struct MergeSort* MergeSort;

MergeSort make_list(int size){
    MergeSort A=(MergeSort)malloc(sizeof(struct MergeSort));
    A->capacity=size;
    A->size=0;
    A->array=malloc(sizeof(int)*size);
    A->tmparray=malloc(sizeof(int)*size);
    return A;
}
void Insert(MergeSort A, int a){
    if (A->size==A->capacity) {
        return;
    }//전체 사이즈와 내부 element의 개수가 같으면 멈추기
    A->array[A->size] = a;
    A->size++;
    //element의 가장 뒤에 a를 insert하고 size를 1만큼 늘리기
}
void printArray(MergeSort A, int l, int r){
    for (int i=l;i<=r;i++) {
        printf("%d ",A->array[i]);
    }//가장 왼쪽부터 오른쪽까지 배열 내부의 모든 element 출력
    printf("\n");
}
void merge(MergeSort A, int l, int m, int r){
    int tmp,num,center,i;
    tmp=l;
    center=m-1;
    num=r-l+1;

    while(l<=center && m<=r)
    {
        if(A->array[l]<=A->array[m])
            A->tmparray[tmp++]=A->array[l++];
        else
            A->tmparray[tmp++]=A->array[m++];
    }

    while(l<=center)
        A->tmparray[tmp++]=A->array[l++];
    while(m<=r)
        A->tmparray[tmp++]=A->array[m++];
    
    for(i=0;i<num;i++,r--)
        A->array[r]=A->tmparray[r];
}

void RmergeSort(MergeSort A, int l, int r){
    int m =(r+l)/2;
    if (l<r){    
        RmergeSort(A,l,m);
        RmergeSort(A,m+1,r);
        merge(A,l,m+1,r);
        printArray(A,l,r);
    }//l보다 r이 작으면 중간을 기준으로 배열을 나눈 뒤, 하위 배열에서 sort를 진행 후 다시 merge
}//Recursive MergeSort
void ImergeSort(MergeSort A, int n){
    int size,l,r,center;
    for(size=1; size<n; size=size*2){
        for(l=0;l<n;l+=2*size){
            center=l+size-1;
            r=center+size;
            if(r>n)   
                r=n;
            if(center>=r)    
                center=(l+r)/2;
            merge(A,l,center+1,r);
            printArray(A,l,r);
        }
    }
}//Iterative MergeSort
int main(int argc, char* argv[]){
    int size,key;
    int *iter_tmp, *rec_tmp;
    FILE *fi=fopen(argv[1],"r");
    MergeSort iter_m, rec_m;

    fscanf(fi, "%d", &size);

    iter_m=make_list(size);
    rec_m=make_list(size);

    for(int i=0;i<size;i++){
        fscanf(fi,"%d",&key);
        Insert(iter_m,key);
        Insert(rec_m,key);
    }
    printf("input: \n");
    printArray(iter_m,0,iter_m->size-1);
    printf("\n");

    printf("iterative: \n");
    ImergeSort(iter_m,iter_m->size-1);
    printf("\n");

    printf("recursive: \n");
    RmergeSort(rec_m,0,rec_m->size-1);
    printf("\n");

    free(iter_m->array);
    free(iter_m->tmparray);
    free(iter_m);
    free(rec_m->array);
    free(rec_m->tmparray);
    free(rec_m);
}
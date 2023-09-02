#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QuickSort{
    int capacity;
    int size;
    int *array;
};

typedef struct QuickSort* QuickSort;

QuickSort make_list(int size){
    QuickSort q=(QuickSort)malloc(sizeof(struct QuickSort));
    q->capacity=size;
    q->size=0;
    q->array=(int*)malloc(size*sizeof(int));
    return q;
}
void Insert(QuickSort q, int a){
    if (q->size==q->capacity) {
        return;    
    }//전체 사이즈와 내부 element의 개수가 같으면 멈추기
    q->array[q->size++] = a;
    //element의 가장 뒤에 a를 insert하고 size를 1만큼 늘리기
}
void printArray(QuickSort q, int pivot){
    printf("pivot value: %d\n",q->array[pivot]);
    printf("result: ");
    for(int i=0;i<q->size;i++){
        printf("%d ",q->array[i]);
    }
    printf("\n");
}//pivot value와 sort후 모든 요소들을 출력
void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int middle_partition(QuickSort q, int low, int high){
    int middle=(low+high)/2;
    int pivot=q->array[middle];
    int i=low;
    int j=high;

    for(;;){
        while(q->array[i]<pivot){
            i++;
        }//pivot보다 작지 않은 값을 찾을 때까지 i를 증가시킴
        while(q->array[j]>pivot){
            j--;
        }//pivot보다 크지 않은 값을 찾을 때까지 j를 감소시킴
        
        if(i>=j){
            return j;//partition이 완료되면 j를 반환 (j=분할 인덱스)
        }else{
            swap(&q->array[i],&q->array[j]);
        }//partition이 아직 안됐으면 swap을 partition을 완료할 때까지 반복

        // if(q->array[i]==pivot){
        //     j--;
        // }
        // if(q->array[j]==pivot){
        //     i++;
        // }
    }
}
int leftmost_partition(QuickSort q, int left, int right){
    int pivot=q->array[left];//pivot을 가장 왼쪽 index에 해당하는 값으로 설정
    int i=left;
    int j=right+1;
    for(;;){
        while(q->array[--j]>pivot);
        while(q->array[++i]<=pivot){
            if(i>right){
                i=left;
                break;
            }
        }//j의 인덱스가 pivot보다 작아지거나 i의 index가 pivot보다 커질때까지 반복, i가 right보다 크면 i를 left라고 설정하고 반복문을 중단
        if(i==left){
            swap(&q->array[i],&q->array[j]);
            return j;
        }//i가 left와 같으면 swap을 하고 j를 반환
        if(i<j){
            swap(&q->array[i],&q->array[j]);
        }else{
            swap(&q->array[j],&q->array[left]);
            return j;
        }
    }
}
int rightmost_partition(QuickSort q, int left, int right) {
    int pivot=q->array[right];//pivot을 가장 오른쪽 index에 해당하는 값으로 설정
    int i=left-1;
    int j=right;
    
    for(;;){
        while(q->array[--j] >= pivot){
            if (j==left){
                j=right;
                break;
            }
        }//j의 인덱스가 pivot보다 작아질때까지 반복하다가 j==left이면 j를 right로 설정하고 반복문 중단
        while (q->array[++i] < pivot);//i의 인덱스를 늘려가면서 i의 인덱스에 해당하는 값이 pivot보다 커질때까지 반복
        if(j==right){
            swap(&q->array[i],&q->array[j]);
            return i;
        }//j==right이면 swap을 하고 i를 반환
        if(i<j){
            swap(&q->array[i],&q->array[j]);
        }else{
            swap(&q->array[i],&q->array[right]);
            return i;
        }//i<j이면 i,j에 해당하는 값을 swap을하고, i>=j이면 i와 right에 해당하는 값을 swap
    }
}

void quicksort(QuickSort q, int left, int right, int type){
    int pivot;
    if(left>=right){
        return;
    }//left>=right이면 quicksort 중단
    if(type==0){
        pivot=leftmost_partition(q,left,right);//type==0(leftmost)이면 leftmost_partition 진행
    }else if(type==1){
        pivot=rightmost_partition(q,left,right);//type==1(rightmost)이면 rightmost_partition 진행
    }else if(type==2){
        pivot=middle_partition(q,left,right);//type==2(middle)이면 middle_partition 진행
    }
    printArray(q,pivot);//quicksort과정 출력
    quicksort(q,left,pivot-1,type);//왼쪽 quicksort
    quicksort(q,pivot+1,right,type);//오른쪽 quicksort
}

int main(int argc, char*argv[]){
    char type_s[10];
    int list_size, key, type_i;
    QuickSort q;
    FILE *fi=fopen(argv[1],"r");
    
    int pivot;
    fscanf(fi,"%s",type_s);
    if(!(strcmp(type_s,"leftmost"))){
        type_i=0;//type_s와 "leftmost"가 같으면 type_i=0을 반환
    }else if(!(strcmp(type_s,"rightmost"))){
        type_i=1;//type_s와 "rightmost"가 같으면 type_i=1을 반환
    }else if(!(strcmp(type_s,"middle"))){
        type_i=2;//type_s와 "middle"이 같으면 type_i=2을 반환
    }
    fscanf(fi,"%d",&list_size);
    q=make_list(list_size);
    for(int i=0;i<list_size;i++){
        fscanf(fi,"%d",&key);
        Insert(q,key);
    }
    
    quicksort(q,0,list_size-1,type_i);
    free(q->array);
    free(q);
    return 0;
}
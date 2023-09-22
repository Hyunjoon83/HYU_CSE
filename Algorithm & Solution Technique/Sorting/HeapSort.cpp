#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void Heapify(vector<int>& A, int len, int parent){
    int largest=parent;
    int leftchild=2*parent+1;
    int rightchild=2*parent+2;

    if(leftchild<len && A[leftchild]>A[largest]){
        largest=leftchild;
    }
    if(rightchild<len && A[rightchild]>A[largest]){
        largest=rightchild;
    }

    if(largest!=parent){
        swap(&A[parent],&A[largest]);
        Heapify(A,len,largest);
    }
}
void HeapSort(vector<int>& A, int len){
    for(int i=(len/2)-1;i>=0;i--){
        Heapify(A,len,i);
    }
    for(int i=len-1;i>0;i--){
        swap(&A[0],&A[i]);
        Heapify(A,i,0);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    HeapSort(A,N);
    for(int i=0;i<N;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
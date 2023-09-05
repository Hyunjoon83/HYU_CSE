#include <iostream>
using namespace std;

void Merge(int* A, int p, int mid, int r){
    int i=p, j=mid+1, t=1;
    
    int tmp[r-p+1];
    while(i<=mid && j<=r) {
        if(A[i]<=A[j]){
            tmp[t++]=A[i++];
        }else{
            tmp[t++]=A[j++];
        }
    }
    while(i<=mid){
        tmp[t++]=A[i++];
    }
    while(j<=r){
        tmp[t++]=A[j++];
    }
    for(int k=p,t=1;k<=r;k++,t++){
        A[k]=tmp[t];
    }
}

void MergeSort(int* A, int p, int r){
    if(p<r){
        int mid=(p+r)/2;
        MergeSort(A,p,mid);
        MergeSort(A,mid+1,r);
        Merge(A,p,mid,r);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A[]={5,2,4,7,1,3,2,6};
    for(int i=0;i<8;i++){
        cout<<A[i]<<" ";
    }
    cout<<'\n';

    MergeSort(A,0,7);

    for(int i=0;i<8;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
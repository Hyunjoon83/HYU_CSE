#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int>& A,int p, int r){
    int pivot=A[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(A[j]<=pivot){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void QuickSort(vector<int>& A, int p, int r){
    if(p<r){
        int q=Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
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
    QuickSort(A,0,N-1);
    for(int i=0;i<N;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
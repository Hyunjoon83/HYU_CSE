#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int>& A, int p, int r){
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

int QuickSelect(vector<int>& A, int p, int r, int i){
    if(p==r)
        return A[p];
    
    int q=Partition(A,p,r);
    int k=q-p+1;

    if(i==k)
        return A[q];
    else if(i<k)
        return QuickSelect(A,p,q-1,i);
    else
        return QuickSelect(A,q+1,r,i-k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    
    int i;
    cin>>i;

    int result=QuickSelect(A,0,N-1,i);
    cout<<"The "<<i<<"th smallest element is: "<<result<< endl;

    return 0;
}
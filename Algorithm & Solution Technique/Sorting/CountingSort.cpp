#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;
    
    int K=0;
    vector<int> A(N+1);
    
    for(int i=1;i<=N;i++){
        cin>>A[i];
        if(A[i]>K)
            K=A[i];
    }

    vector<int> C(K+1,0);
    for(int i=1;i<=N;i++){
        C[A[i]]++;
    }
    for(int i=1;i<=K;i++){
        C[i]+=C[i-1];
    }

    vector<int> B(N+1);
    for(int i=N;i>=1;i--){
        B[C[A[i]]]=A[i];
        C[A[i]]--;
    }

    for(int i=1;i<=N;i++){
        cout<<B[i]<<" ";
    }
    return 0;
}
#include <iostream>
using namespace std;

void SelectionSort(int* arr, int N){
    int index;
    for(int i=0;i<N-1;i++){
        index=i;
        for(int j=i+1;j<N;j++){
            if(arr[j]<arr[index]){
                index=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[]={5,2,4,6,1,3};

    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';

    SelectionSort(arr,6);

    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
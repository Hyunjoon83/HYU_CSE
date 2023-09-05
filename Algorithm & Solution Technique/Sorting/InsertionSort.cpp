#include <iostream>
using namespace std;

void InsertionSort(int* arr){
    int i,j,key;
    for(i=0;i<6;i++){
        key=arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j]>key){
                arr[j+1]=arr[j];
            }else{
                break;
            }
        }
        arr[j+1]=key;
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

    InsertionSort(arr);

    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
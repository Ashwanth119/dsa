#include <iostream>
#include <vector>
using namespace std;

// Non-decreasing order implementation of insertion sort.
void insertionSort(vector<int>& arr, int n){
	for(int i=1;i<n;i++){
        int key=arr[i];
        int idx=i-1;
        while(idx>=0){
            if(arr[idx]>key)
                arr[idx+1]=arr[idx];
            else
                break;
            idx--;
        }
        arr[idx+1]=key;
    }
}

void printArray(vector<int>& arr, bool sorted){
    cout<< (sorted?"Array after sorting\n" : "Array before sorting\n");
    for(int val:arr){
        cout<<val<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printArray(arr,false);
    insertionSort(arr,n);
    printArray(arr,true);
}

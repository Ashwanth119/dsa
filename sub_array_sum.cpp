#include<bits/stdc++.h>
using namespace std;

int maxContiguousSubsequenceSum(vector<int>& arr, int idx, int n){
    if(idx==n)
        return 0;
    return arr[idx]+
}
int maxSubArraySum(vector<int>& arr, int n){
    return maxContiguousSubsequenceSum(arr,0,n);
    /*
        Kadane's Algorithm
    */
    // int maxSum=INT_MIN;
    // int curSum=0;
    // for(int i=0;i<n;i++){
    //     curSum+=arr[i];
    //     maxSum=max(curSum,maxSum);
    //     if(curSum<0)
    //         curSum=0;
    // }
    // return maxSum;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        arr.push_back(val);
    }
    cout<<maxSubArraySum(arr,n);
}
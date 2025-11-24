#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int>& arr, int n){
    for(auto val:arr)
        cout<<val<<" ";
    cout<<endl;
}
vector<int> twoRT(vector<int>& arr, int n){
    int x=0;
    for(int val:arr)
        x^=val;
    for(int i=1;i<=n-2;i++)
        x^=i;
    int leastSetBit=0;
    while(x){
        if(x&1)
            break;
        leastSetBit++;
        x>>=1;
    }
    int ele1=0,ele2=0;
    for(int i=0;i<n;i++){
        if(arr[i]&(1<<leastSetBit))
            ele1^=arr[i];
        else
            ele2^=arr[i];
    }
    for(int i=1;i<=n-2;i++){
        if(i&(1<<leastSetBit))
            ele1^=i;
        else
            ele2^=i;
    }

    return {ele1,ele2};
}
int main(){
    int n;
    cin>>n;
    /*
        --> 1<=arr[i]<=n-2
        --> Two elements repeat twice, while other elements have a frequency 1

    */
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    // Find those 2 elements, which are repeating twice
    vector<int> ans=twoRT(arr,n);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}
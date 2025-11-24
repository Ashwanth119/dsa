#include<bits/stdc++.h>
using namespace std;

int f(int n){
    if(n==0 || n==1)
        return 2;
    int val=0;
    for(int i=1;i<n;i++){
        val+=2*f(i)*f(i-1);
    }
    return val;
}
int main(){
    int n;
    cin>>n;
    cout<<f(n);
}

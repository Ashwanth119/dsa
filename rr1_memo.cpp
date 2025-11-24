#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<int>& dp){
    if(n==0 || n==1)
        return 2;
    if(dp[n]!=-1)
        return dp[n];
    int val=0;
    for(int i=1;i<n;i++){
        val+=2*f(i,dp)*f(i-1,dp);
    }
    return dp[n]=val;
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    dp[0]=dp[1]=2;
    cout<<f(n,dp);
}

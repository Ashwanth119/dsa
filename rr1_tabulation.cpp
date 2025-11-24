#include<bits/stdc++.h>
using namespace std;

// int fun(int n){
//     vector<int> dp(n+1,0);
//     dp[0]=dp[1]=2;
//     for(int i=2;i<=n;i++){
//         for(int j=1;j<i;j++){
//             dp[i]+=2*dp[j]*dp[j-1];
//         }
//     }
//     return dp[n];
// }
int fun(int n){
    vector<int> dp(n+1,0);
    dp[0]=dp[1]=2;
    dp[2]=2*dp[0]*dp[1];
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+2*dp[i-1]*dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fun(n);
}

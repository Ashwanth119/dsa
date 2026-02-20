#include <bits/stdc++.h>
using namespace std;


int LCS(string &s1, string &s2){
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(s1[i] == s2[j])
                dp[i+1][j+1] = dp[i][j]+1;
            else
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
        }
    }

    // print the lcs
    int i=m, j=n;
    string lcs="";
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            lcs=s1[i-1]+lcs;
            i--;
            j--;
        }
        else if(dp[i][j-1]>=dp[i-1][j]){
            j--;
        }
        else{
            i--;
        }
    }
    cout<<lcs<<endl;
    return dp[m][n];
}


int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<LCS(s1,s2)<<endl;
    return 0;
}
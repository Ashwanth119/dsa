#include<bits/stdc++.h>
using namespace std;
void allStringsOfNBits(string &str,int n){
    if(n==0){
        cout<<str<<endl;
        return;
    }
    str[n-1]='0';
    allStringsOfNBits(str,n-1);
    str[n-1]='1';
    allStringsOfNBits(str,n-1);
}
int main(){
    int n;
    cin>>n;
    string str(n,' ');
    // for(int i=0;i<n;i++)
    //     str+=' ';
    allStringsOfNBits(str,n);
    return 0;
}
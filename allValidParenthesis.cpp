#include<bits/stdc++.h>
using namespace std;
void generateAllValidPar(int n, int oc, int cc, char str[], int idx){
    if(oc+cc==n){
        str[idx]='\0';
        cout<<str<<endl;
        return;
    }
    if(oc<n/2){
        str[idx]='(';
        generateAllValidPar(n,oc+1,cc,str,idx+1);
    }
    if(cc<oc){
        str[idx]=')';
        generateAllValidPar(n,oc,cc+1,str,idx+1);
    }
}
int main(){
    int n;
    cin>>n;
    char str[n+1];
    generateAllValidPar(n,0,0,str,0);
}
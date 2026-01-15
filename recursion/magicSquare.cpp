#include<bits/stdc++.h>
using namespace std;

class GP{
    vector<int> permute;
    vector<bool> valid;
    int n;
    public:
        GP(int n) : permute(n,0), valid(n+1,true), n(n){}
        
        void generatePermutation(){
            getPermutation(permute,valid,0);
        }

        void printArray(const vector<int>& arr){
            for(int val:arr)
                cout<<val<<" ";
            cout<<endl;
        }

        bool isMagicSquare(const vector<int>& arr){
            int k=sqrt(n);
            int tar=(n*(n+1))/2*k;
            int sum=0;
            
        }

        void getPermutation(vector<int> &permute, vector<bool>& valid, int idx){
            if(idx==n){
                printArray(permute);
                return;
            }
            for(int i=1;i<=n;i++){
                if(valid[i]){
                    permute[idx]=i;
                    valid[i]=false;
                    getPermutation(permute,valid,idx+1);
                    valid[i]=true;
                }
            }
        }

};
int main(){
    int n;
    cin>>n;
    GP gp(n);
    gp.generatePermutation();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class QuickFind
{
private:
    vector<int> arr;

public:
    QuickFind(int n){
        arr.resize(n);
        for(int i=0;i<n;i++)
            arr[i]=i;
    }

    void getArr(){
        for(int num:arr)
            cout<<num<<" ";
        cout<<endl;
    }

    // If parent of p and q are equal then we return true, else we return false
    bool findConnection(int p, int q){
        return arr[p]==arr[q];
    }

    // If there is an edge between p and q, then we set all the indices that contain pid as a parent then we change it to the qid
    void unionNodes(int p, int q){
        int pid = arr[p];
        int qid = arr[q];
        for(int i=0;i<arr.size();i++){
            if(arr[i]==pid){
                arr[i]=qid;
            }
        }
    }
};

int main()
{
    QuickFind qf(10);
    qf.unionNodes(0,5);
    qf.unionNodes(5,6);
    qf.unionNodes(1,6);
    qf.unionNodes(1,2);
    qf.unionNodes(2,7);
    qf.unionNodes(3,8);
    qf.unionNodes(3,4);
    qf.unionNodes(4,9);
    qf.getArr();
    cout<<qf.findConnection(0,9);
    cout<<qf.findConnection(8,9);
    cout<<qf.findConnection(1,7);
    return 0;
}
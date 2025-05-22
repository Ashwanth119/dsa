#include<bits/stdc++.h>
using namespace std;

class QuickUnion{
private:
    vector<int> arr;
public:
    QuickUnion(int n){
        arr.resize(n);
        for(int i=0;i<n;i++)
            arr[i]=i;
    }

    void getArr(){
        for(int ele:arr)
            cout<<ele<<" ";
        cout<<endl;
    }

    int findParent(int p){
        while(p!=arr[p])
            p=arr[p];
        return p;
    }

    bool findConnection(int p, int q){
        return findParent(p)==findParent(q);
    }

    void unionNodes(int p, int q){
        arr[findParent(p)]=findParent(q);
    }
};

int main()
{
    QuickUnion qu(10);
    qu.unionNodes(0,5);
    qu.unionNodes(5,6);
    qu.unionNodes(1,6);
    qu.unionNodes(1,2);
    qu.unionNodes(2,7);
    qu.unionNodes(3,8);
    qu.unionNodes(3,4);
    qu.unionNodes(4,9);
    qu.getArr();
    cout<<qu.findConnection(0,9);
    cout<<qu.findConnection(8,9);
    cout<<qu.findConnection(1,7);
    return 0;
}
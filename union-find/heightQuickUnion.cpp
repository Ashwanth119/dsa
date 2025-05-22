#include <bits/stdc++.h>
using namespace std;

class HeightQuickUnion
{
private:
    vector<int> arr;
    vector<int> height;

public:
    HeightQuickUnion(int n)
    {
        arr.resize(n);
        height.resize(n, 0);
        for (int i = 0; i < n; i++)
            arr[i] = i;
    }

    void getArr()
    {
        for (int ele : arr)
            cout << ele << " ";
        cout << endl;
        for (int ele : height)
            cout << ele << " ";
        cout << endl;
    }

    int findParent(int p)
    {
        if (p != arr[p])
            arr[p] = findParent(arr[p]);
        return arr[p];
    }

    bool findConnection(int p, int q)
    {
        return findParent(p) == findParent(q);
    }

    void unionNodes(int p, int q)
    {
        int pid = findParent(p);
        int qid = findParent(q);
        if (pid == qid)
            return;
        if (height[pid] > height[qid])
        {
            arr[qid] = pid;
        }
        else if (height[pid] < height[qid])
        {
            arr[pid] = qid;
        }
        else
        {
            arr[pid] = qid;
            height[qid]++;
        }
    }
};

int main()
{
    HeightQuickUnion hqu(10);
    hqu.unionNodes(0, 5);
    hqu.unionNodes(5, 6);
    hqu.unionNodes(1, 6);
    hqu.unionNodes(1, 2);
    hqu.unionNodes(2, 7);
    hqu.unionNodes(3, 8);
    hqu.unionNodes(3, 4);
    hqu.unionNodes(4, 9);
    hqu.getArr();
    cout << hqu.findConnection(0, 9);
    cout << hqu.findConnection(8, 9);
    cout << hqu.findConnection(1, 7);
    return 0;
}
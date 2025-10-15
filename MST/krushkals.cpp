#include <bits/stdc++.h>
using namespace std;
// User function Template for C++
class DSU{
    
    vector<int> parent, rank;
    
    public:
        DSU(int n){
            parent.resize(n);
            rank.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=1;
            }
        }
        
        int find(int x){
            return (parent[x]==x) ? x : parent[x]=find(parent[x]);
        }
        
        void unite(int x, int y){
            int px=find(x);
            int py=find(y);
            if(px!=py){
                if(rank[px]<rank[py])
                    parent[px]=py;
                else if(rank[px]>rank[py])
                    parent[py]=px;
                else{
                    parent[py]=px;
                    rank[px]++;
                }
            }
        }
};

class Solution {
  public:
  
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),[](const vector<int> &a, const vector<int> &b){
            return a[2]<b[2];
        });
        
        DSU dsu(V);
        int cost=0, newEdges=0;
        
        for(auto &e:edges){
            int x=e[0], y=e[1], weight=e[2];
            // cout<<x<<" "<<y<<" "<<weight<<endl;
            if(dsu.find(x)!=dsu.find(y)){
                dsu.unite(x,y);
                cost+=weight;
                newEdges++;
                if(newEdges==V-1)
                    break;
            }
            
        }
        return cost;
        
    }
};

int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> arr;
    for(int i=0;i<E;i++){
        int x,y,w;
        cin>>x>>y>>w;
        arr.push_back({x,y,w});
    }
    Solution obj;
    cout<<obj.kruskalsMST(V,arr);
}
#include <bits/stdc++.h>
using namespace std;

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
  
    int boruvkasMST(int V, vector<vector<int>> &edges) {
        // code here
        
        DSU dsu(V);
        int cost=0, curComponents=V;
        vector<vector<int>> cheapest(V,vector<int>(3,-1));
        
        while(curComponents>1){
            for(auto &edge:edges){
                int u=edge[0], v=edge[1], w=edge[2];
                int p1=dsu.find(u);
                int p2=dsu.find(v);
                if(p1!=p2){
                    if(cheapest[p1][2]==-1 || cheapest[p1][2]>w)
                        cheapest[p1] = {u,v,w};
                    if(cheapest[p2][2]==-1 || cheapest[p2][2]>w)
                        cheapest[p2] = {u,v,w};
                }
            }
            
            for(int i=0;i<V;i++){
                if(cheapest[i][2]!=-1){
                    int u=cheapest[i][0], v=cheapest[i][1], w=cheapest[i][2];
                    int pu=dsu.find(u);
                    int pv=dsu.find(v);
                    if(pu!=pv){
                        dsu.unite(u,v);
                        cost+=w;
                        curComponents--;
                    }
                }
                cheapest[i]={-1,-1,-1};
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
    cout<<obj.boruvkasMST(V,arr);
}
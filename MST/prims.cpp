#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adjList(V);
        for(vector<int>& e:edges){
            int u=e[0], v=e[1], w=e[2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<bool> visited(V,false);
        int cost=0;
        while(!pq.empty()){
            pair<int,int> cur=pq.top();
            int node=cur.second;
            int weight=cur.first;
            pq.pop();
            if(visited[node])
                continue;
            visited[node]=true;
            cost+=weight;
            for(pair<int,int> next:adjList[node]){
                if(!visited[next.first]){
                    pq.push({next.second,next.first});
                }
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
    cout<<obj.spanningTree(V,arr);
}
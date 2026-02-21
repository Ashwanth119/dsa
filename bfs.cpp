#include <bits/stdc++.h>
using namespace std;


void bfs(vector<vector<int>> &adjList, int v, int src=0){
    vector<int> dist(v,-1);
    dist[src]=0;
    queue<int> q; // to track the nodes visiting order
    q.push(src);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int node:adjList[cur]){
            if(dist[node]==-1){
                dist[node]=dist[cur]+1;
                q.push(node);
            }
        }
    }

    for(int i=0;i<v;i++){
        cout<<src<<" "<<i<<" "<<dist[i]<<endl;
    }
}


int main(){
    int v;
    cin>>v; // no.of vertices in a graph
    int e;
    cin>>e; // no.of edges in a graph
    vector<vector<int>> adjList(v);
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v; // edge between two vertices u,v
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int src;
    cin>>src; // source node to start the traversal
    bfs(adjList,v,src);
    return 0;
}
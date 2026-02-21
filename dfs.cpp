#include <bits/stdc++.h>
using namespace std;

int t = 0;


void dfsVisit(vector<vector<int>> &adjList, vector<int> &discovery, vector<int> &finish, vector<string> &color, int cur){
    color[cur]="grey";
    t++;
    discovery[cur]=t;
    for(int next:adjList[cur]){
        if(color[next]=="white"){
            dfsVisit(adjList,discovery,finish,color,next);
        }
    }
    t++;
    finish[cur]=t;
    color[cur]="black";
}


void dfs(vector<vector<int>> &adjList, vector<int> &discovery, vector<int> &finish, vector<string> &color, int v){
    for(int i=0;i<v;i++){
        if(color[i]=="white"){
            dfsVisit(adjList,discovery,finish,color,i);
        }
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
        // adjList[v].push_back(u);
    }

    vector<string> color(v,"white");
    vector<int> discovery(v), finish(v);
    t=0;
    dfs(adjList,discovery,finish,color,v);

    for(int i=0;i<v;i++){
        cout<<i<<" "<<color[i]<<" "<<discovery[i]<<" "<<finish[i]<<endl;
    }
    return 0;
}
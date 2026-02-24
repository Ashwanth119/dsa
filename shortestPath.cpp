#include <bits/stdc++.h>
using namespace std;


class ShortestPath {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        
        /* 
            A shortest path between the source and other vertex 
            can have atmost V-1 edges.
        */
        for(int i=0;i<V-1;i++){
            for(vector<int> edge:edges){
                int u = edge[0], v = edge[1], w = edge[2];
                if(dist[u] != INT_MAX && dist[v] > dist[u]+w){
                    dist[v] = dist[u]+w;
                }
            }
        }
        
        // for(int dis:dist)
        //     cout<<dis<<" ";
        // cout<<endl;
        
        /*
            If any path between the source and any vertex, does not relaxed 
            even after traversing V-1 edges between those vertices, 
            then we can declare that there is a negative cycle in the path
        */
        for(vector<int> edge:edges){
            int u = edge[0], v = edge[1], w = edge[2];
            if(dist[u] != INT_MAX && dist[v] > dist[u]+w){
                return {-1};
            }
        }
        return dist;
    }


    vector<vector<pair<int,int>>> getWeightedAdjList(int V, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adjList(V);
        for(vector<int> &edge:edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adjList[u].push_back({v,w});
        }
        return adjList;
    }


    vector<int> topoSort(int V, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adjList = getWeightedAdjList(V,edges);
        vector<int> inEdges(V,0);
        for(vector<int> &edge:edges){
            int u = edge[0], v = edge[1];
            inEdges[v]++;
        }

        queue<int> q;
        vector<int> topoOrder;
        for(int i=0;i<V;i++){
            if(inEdges[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            topoOrder.push_back(cur);
            for(pair<int,int> adj:adjList[cur]){
                int next = adj.first;
                inEdges[next]--;
                if(inEdges[next] == 0)
                    q.push(next);
            }
        }
        return topoOrder;
    }

    vector<int> DAGShortestPath(int V, vector<vector<int>>& edges, int src){
        vector<int> topoOrder = topoSort(V,edges);
        if(topoOrder.size()!=V){
            cout<<"Cannot form topological Order from the given graph";
            return {-1};
        }

        vector<vector<pair<int,int>>> adjList = getWeightedAdjList(V,edges);
        vector<int> dis(V,INT_MAX);
        dis[src] = 0;
        for(int node:topoOrder){
            if(dis[node] == INT_MAX)
                continue;
            for(pair<int,int> next:adjList[node]){
                int u = next.first, w = next.second;
                if(dis[u] > dis[node] + w){
                    dis[u] = dis[node] + w;
                }
            }
        }
        return dis;
    }
};


int main(){
    /*
        Input without negative cycle
    */
    // // Number of vertices in the graph
    // int V = 5;

    // // Edge list representation: {source, destination, weight}
    // vector<vector<int>> edges = {
    //     {1, 3, 2}, 
    //     {4, 3, -1},
    //     {2, 4, 1}, 
    //     {1, 2, 1},
    //     {0, 1, 5} 
    // };


    /*
        Input with negative cycle
    */
    // Number of vertices in the graph
    int V = 4;

    // Edge list representation: {source, destination, weight}
    vector<vector<int>> edges = {
        {0, 1, 5}, 
        {1, 2, -7},
        {2, 3, -8}, 
        {3, 0, 3}
    };

    // Define the source vertex
    int src = 0;

    ShortestPath sp;
    
    // vector<int> ans = sp.bellmanFord(V, edges, src);
    
    // if(ans.size()==1 && ans[0]==-1){
    //     cout<<"Negative cycle detected in the graph\n";
    //     return 1;
    // }
    // for (int dist : ans) 
    //     cout << dist << " ";
    // cout<<endl;

    //topoSort of a graph
    vector<int> topoOrder = sp.topoSort(V,edges);
    for(int val:topoOrder)
        cout<<val<<" ";
    cout<<endl;

    vector<int> DAGsp = sp.DAGShortestPath(V,edges,src);
    if(DAGsp.size()==1 && DAGsp[0]==-1){
        return 1;
    }
    for(int val:DAGsp)
        cout<<val<<" ";
    cout<<endl;
    return 0; 
}
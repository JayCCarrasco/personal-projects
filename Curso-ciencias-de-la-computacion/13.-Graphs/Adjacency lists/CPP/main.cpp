//Librerías
#include <iostream>
#include <vector>
#include <queue>

std::vector<bool> visited(8, false);

//bfs
void bfs(std::vector<std::vector<int>>& adj){
    int V = adj.size();
    std::vector<int> res;

    std::queue<int> q;

    int src = 0;
    visited[src] = true;
    q.push(src);

    while (!q.empty()){
        int curr = q.front();
        std::cout << curr << " ";
        q.pop();
        res.push_back(true);

        for(int x : adj[curr]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

//dfs
void dfs(std::vector<std::vector<int>>& adj, int v){
    int V = adj.size();    
    visited[v] = true;
    std::cout << v << " ";   

    for(int x : adj[v]){   
        if(!visited[x]){
            visited[x] = true;
            dfs(adj, x);
            
        } 
    }
}


//addEdge
void addEdge(std::vector<std::vector<int>>& adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    int V = 8;
    std::vector<std::vector<int>> directedGraph(V);

    addEdge(directedGraph, 0, 1);
    addEdge(directedGraph, 0, 6);
    addEdge(directedGraph, 0, 7);
    addEdge(directedGraph, 1, 2);
    addEdge(directedGraph, 1, 4);
    addEdge(directedGraph, 1, 6);
    addEdge(directedGraph, 2, 3);
    addEdge(directedGraph, 2, 4);
    addEdge(directedGraph, 3, 4);
    addEdge(directedGraph, 4, 5);

    //bfs(directedGraph);
    dfs(directedGraph,0);
    return 0;
}
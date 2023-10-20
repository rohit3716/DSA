#include<bits/stdc++.h>
using namespace std;

void addEdge( vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print( vector<int> adj[], int v){
    for (int i = 0; i < v; i++)
    {
        cout<<i<<"->";
        for( auto v:adj[i] ){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    
}

void dfsRec( vector<int> adj[], int s, vector<bool>& visited) {
    visited[s] =true;
    cout<<s<<" ";
    for( auto u:adj[s] ){
        if( visited[u] == false ){
            dfsRec( adj, u, visited);
        }
    }
}

void dfs( vector<int> adj[], int v, int s) {
    vector<bool> visited(v, false);
    
    for (int i = 0; i < v; i++)
    {
        if( visited[i] == false ){
            dfsRec( adj, i, visited);
        }
    }
    
}

int main() {

    int v = 8;

    vector<int> adj[v];

    addEdge( adj, 0, 1);
    addEdge( adj, 0, 2);
    addEdge( adj, 1, 3);
    addEdge( adj, 1, 4);
    addEdge( adj, 2, 3);

    addEdge( adj, 5, 6);
    addEdge( adj, 6, 7);

    print( adj, v);
    cout<<"DFS :-";
    dfs( adj, v, 0);


    return 0;
}
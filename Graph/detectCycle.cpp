#include<bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[] ){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool dfsRec( vector<int> adj[], int s, vector<bool>& visited, int parent){
    visited[s] = true;
    for( auto u:adj[s] ){
        if( visited[u] == false ){
            if( dfsRec( adj, u, visited, s) )
                return true;
        }
        else if( u != parent ){
            return true;
        }
    }
    return false;
}

bool isCycle( vector<int> adj[], int v, int s){
    vector<bool> visited( v, false);

    for (int i = 0; i < v; i++)
    {
        if( visited[i] == false ){
            if( dfsRec( adj, i, visited, -1))
                return true;
        }
    }
    return false;
}

int main(){

    int v = 6;

    vector<int> adj[v];

    addEdge( 0, 1, adj);
    addEdge( 1, 2, adj);
    addEdge( 2, 3, adj);
    addEdge( 3, 1, adj);
    addEdge( 2, 4, adj);
    addEdge( 4, 5, adj);


    if( isCycle( adj, v, 0) )
        cout<<"cycle is present in the Graph."<<endl;
    else    
        cout<<"cycle is not present in the given graph."<<endl;

    return 0;
}
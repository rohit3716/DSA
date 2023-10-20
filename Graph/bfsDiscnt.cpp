#include<bits/stdc++.h>
using namespace std;

void addEdge( vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print( vector<int> adj[], int v){
    for( int i = 0; i < v; i++){
        cout<<i<<"->";
        for( auto v:adj[i] ){
            cout<<v<<" ";
        }
        cout<<endl;
    }
}

void BFS(vector<int> adj[], int s, vector<bool>& visited ){
    // vector<bool> visited(v+1, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    int count = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for( auto v:adj[u] ){
            if( visited[v] == false ){
                count++;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


int main(){

    int v = 7;

    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge( adj, 0, 2);
    addEdge( adj, 1, 3);
    addEdge( adj, 2, 3);

    addEdge( adj, 4, 5);
    addEdge( adj, 4, 6);
    addEdge( adj, 5, 6);

    // print( adj, v);

    cout<<"BFS:-"<<endl;

    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++)
    {
        if(visited[i] == false ){
            BFS(adj, i, visited);
        }
    }
    

    // BFS(adj, 0, v);
    // BFSdis( adj, v);

    return 0;
}
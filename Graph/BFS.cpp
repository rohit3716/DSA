#include<bits/stdc++.h>
using namespace std;

void addEdge( int u, int v, vector<int> adj[]){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph( vector<int> adj[], int v) {
    for (int i = 0; i < v; i++)
    {
        cout<<i<<"->";
        for( auto v:adj[i] ){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    
}

// void BFS( vector<int> adj[], int v, int s){
    
//     vector<bool> visited( v+1, false);

//     queue<int> q;

//     q.push(s);
//     visited[s] =true;

//     cout<<"BFS:- "<<endl;

//     while( !q.empty() ) {
//         int u = q.front();
//         q.pop();
//         cout<<u<<" ";
//         for( auto i:adj[u] ){
//             if( visited[i] == false ){
//                 visited[i] = true;
//                 q.push(i);
//             }
//         }
//     }
// }

void BFS( vector<int> adj[], int v, int s){
    vector<bool> visited( v+1, false);

    queue<int> q;

    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u <<" ";
        for( auto v:adj[u] ){
            if( visited[v] == false ){
                q.push(v);
                visited[v] =true;
            }
        }
    }
    
}

int main(){
    
    int v = 5;

    vector<int> adj[v];

    addEdge( 0, 1, adj);
    addEdge( 0, 2, adj);
    addEdge( 1, 3, adj);
    addEdge( 1, 2, adj);
    addEdge( 2, 3, adj);
    addEdge( 2, 4, adj);
    addEdge( 3, 4, adj);

    printGraph( adj, v);

    cout<<"BFS -> "<<endl;

    BFS( adj, v, 0);
    
    return 0;
}
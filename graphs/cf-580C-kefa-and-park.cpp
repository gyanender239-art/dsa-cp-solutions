//Link: https://codeforces.com/problemset/problem/580/C

/*
Approach: starting at the root vertex(1) when we enter a node we check if it contains a cat, if it does then we increment our consecat counter else we reset it to zero since the consecutive chain broke. then we check for the condition of consecat>m, it is it true we just return and dont go further down that path otherwise we keep going down until we reach a leaf node and increment out paths counter, registering the current path as a valid one
*/ 

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj,int u,int &paths,int m,vector<int>&cats,int consecat,vector<bool>&visited){
    visited[u] = true;
    if(cats[u]) consecat++;
    else consecat = 0;
    if(consecat > m) return;
    bool leaf = true;
    for(int &v:adj[u]){
        if(!visited[v]){
            if(leaf) leaf = false;
            dfs(adj,v,paths,m,cats,consecat,visited);
        }
    }
    if(leaf) paths++;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> cats(n+1);
    for(int i = 1;i<n+1;i++) cin>>cats[i];
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1,false);
    for(int i = 0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int paths = 0;
    dfs(adj,1,paths,m,cats,0,visited);
    cout<<paths;
    
}
int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
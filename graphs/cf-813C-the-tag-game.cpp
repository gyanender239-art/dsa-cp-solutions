//Link: https://codeforces.com/problemset/problem/813/C

/*
Approach:
bob has to reach to the deepest level but the problem sometimes was that for bob to go to the 
deepest node he had to travel to some nodes first but in some cases alice reached there faster than bob
so we made distance arrays for alice and bob to store the distance both had to travel to reach a certain node
now if alice reached a node before bob or at the next move bob reaches it (distA[i] <= dist[B]) we dont consider
that node for bob to go to. with that, we just pick each node where bob can reach, check the number of moves it takes
(2*distA[i]) and update our ans variable with the max number of moves.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj,int u,int p, int d, vector<int>&dist){
    dist[u] = d;
    for(int v:adj[u]){
        if(v != p){
            dfs(adj,v,u,d+1,dist);
        }
    }
}

void solve(){
    int n,x;
    cin>>n>>x;
    vector<vector<int>> adj(n+1);
    vector<int> distA(n+1),distB(n+1);
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(adj,1,-1,0,distA);
    dfs(adj,x,-1,0,distB);

    int ans = 0;
    for(int i = 2;i<=n;i++){
        if(distB[i] < distA[i]){
            ans = max(ans,2*distA[i]);
        }
    }
    cout<<ans;

    
}
int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
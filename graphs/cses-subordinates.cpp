//Link: https://cses.fi/problemset/task/1674

/*Approach: the problem makes a tree so at a node i ask its children how many nodes are below them + the children included. i maintain a count to count the number of subordinates and a boolean to check if the current node is a leaf node. if it is a leaf node that means it has zero subordinates and it should return 1 to its parent meaning its the only node in its subtree. else if its not a leaf node i just take the answer from the children add them to my count, update the count of subordinates and return the count of the subordinates+1 to the parent*/ 

#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>&adj,int u,vector<int>&subs){
    int cnt = 0;
    bool neighbors = false;
    for(int &v:adj[u]){
        neighbors = true;
        cnt += dfs(adj,v,subs);
    }

    subs[u] = cnt;
    if(!neighbors) return 1;
    return (cnt+1);

}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 2;i<=n;i++){
        int ele;
        cin>>ele;
        adj[ele].push_back(i);
    }
    //sol
    vector<int> subs(n+1,0);
    dfs(adj,1,subs);

    for(int i = 1;i<n+1;i++){
        cout<<subs[i]<<" ";
    }
    
}
int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}

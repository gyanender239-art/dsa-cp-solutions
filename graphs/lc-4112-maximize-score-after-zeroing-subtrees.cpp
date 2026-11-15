//Link: https://leetcode.com/problems/maximize-score-after-zeroing-subtrees/description/

/*
Approach:
we have to perform some operations and maximize the sum of scores by doing so. 
the operation is that we have to choose one child of our current node and make the sum of score its subtree = 0,
if op[u] = 0(option to perform operation or not)
if op[u] = 1(mandatory to perform the operation)

computing sum = at a node i take the values my neighbors/children nodes give me, add them and add my node's value
and send them upto the parent
for the operation, we just have to reject the value of one of the children

since we have to maximise the sum. for op = 1:- we can just choose to reject the value of children which is minimum
out of all
for op = 0: the only case in which we have to reject a value is when the value is negative

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int dfs(vector<vector<int>>&adj,int u,int p,vector<int>&op,vector<int>&score){
        bool isLeaf = true;
        int mn = INT_MAX;
        int sum = score[u];
        for(int v:adj[u]){
            if(v != p){
                isLeaf = false;
                int neighbor = dfs(adj,v,u,op,score);
                if(mn>neighbor) mn = neighbor;
                sum += neighbor;
            }
        }
        if(isLeaf) return sum;
        if(op[u] == 1 || mn<0){
            return sum-mn; 
        }
        return sum;
    }
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++){
            if(parent[i] != -1){
                adj[parent[i]].push_back(i);
            }
        }
        return dfs(adj,0,-1,op,score);
    }
};
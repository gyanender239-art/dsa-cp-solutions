//Link: https://codeforces.com/problemset/problem/378/C

/*Approach: i mark a cell only after all its neighbours have been fully explored. in this postorder traversal the child is processed before the parent so when i mark a cell that means all of the neighbors/children below it are already marked. and removing the deepest node(leaf) doesnt divide the connected component*/ 

#include <bits/stdc++.h>
using namespace std;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

void dfs(vector<string>& maze,vector<vector<bool>>&visited,int r,int c, int& k,int n, int m){
    visited[r][c] = true;

    for(int d = 0;d<4;d++){
        int nr = r + dr[d];
        int nc = c + dc[d];
        if(nr<0 || nc<0 || nr>=n || nc>=m || maze[nr][nc] == '#' || visited[nr][nc]) continue;
        dfs(maze,visited,nr,nc,k,n,m);
    }

    //after exploring all neighbours
    if(k>0){
        maze[r][c] = 'X';
        k--;
    }

}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> maze(n);
    for(int i = 0;i<n;i++){
        cin>>maze[i];
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));

    //find a source cell to begin dfs
    int sr = -1,sc=-1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(maze[i][j] == '.'){
                sr = i;
                sc = j;
                break;
            }
        }
        if(sr != -1) break;
    }

    dfs(maze,visited,sr,sc,k,n,m);

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<maze[i][j];
        }
        cout<<"\n";
    }
}
int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
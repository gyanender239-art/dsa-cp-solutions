//Link: https://codeforces.com/problemset/problem/727/A

/*
Approach:
as we have only two choices to transform a(2*a and 10*a + 1). we recursively try that until a becomes b.

pruning step: as we're only increasing the number if at some point a>b then we just return false and dont 
explore more in that path

we also maintain a path vector and push_back the current value of a into that, if some branch is found invalid,
before backtracking to explore more branches we remove the current value of a from that path(undo step)
*/

#include <bits/stdc++.h>
using namespace std;

bool recurse(long long a,long long b, vector<long long>&path,vector<long long>&ans){
    if(a==b){
        path.push_back(a);
        ans = path;
        return true;
    }
    else if(a>b) return false;

    path.push_back(a);
    
    if(recurse(2*a,b,path,ans)) return true;

    if(recurse(10*a+1,b,path,ans)) return true;

    path.pop_back();
    
    return false;
}

void solve(){
    long long a,b;
    cin>>a>>b;
    vector<long long> path;
    vector<long long> ans;
    if(recurse(a,b,path,ans)){
        cout<<"YES\n"<<ans.size()<<"\n";
        for(long long &ele:ans){
            cout<<ele<<" ";
        }
    }
    else{
        cout<<"NO";
    }
    
    
}
int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
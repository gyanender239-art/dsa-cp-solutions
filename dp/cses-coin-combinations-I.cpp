//Link: https://cses.fi/problemset/task/1635

/*
Approach:
here we are given some coins {2,3,5} and we have to find the number of distinct ways
to produce sum x = 9. in the given example there are 8 ways:
2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2

think about the last decision we made before adding any of the coins out of three to reach 9
for 2: it is 7 (7+2 = 9)
for 3: it is 6 (6+3 = 9)
for 5: it is 4 (4+5 = 9)
now let us assume that we already have all the answers of these three subproblems
number of distinct ways to produce 7 are 5:
2+5, 5+2, 2+2+3, 2+3+2, 3+2+2 (add 2 to any of them and we get 9)
for 6 it is 2: 3+3, 2+2+2 (add 3 to any of them and we get 9)
for 4 it is 1: 2+2
so in total we have 5+2+1 = 8 distinct ways and these are also the 8 distinct ways to make
9 by just adding a number out of our given set of coins so our answer for the bigger problem is 8

now lets define dp[i] = number of distinct ways to make sum i using the coins given
dp[k] = sum of(dp[k-a[j]]) where a[j]<=k and j = 0 to size of coins array

base case:
dp[0] = 1 as lets take the minimum possible sum that can be made from {2,3,5}
that is 2 so dp[2] = dp[0] (all others are negative which violate a[j]<=k)
and there is actually one way to make 2 which is 2 itself so dp[0] must be 1
now just build the solution from bottom to top final subproblem
*/

#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int MOD = 1e9+7;
    vector<int> dp(x+1,0);
    dp[0] = 1;
    for(int i = 1;i<=x;i++){
        for(int j = 0;j<n;j++){
            if(a[j] <= i){
                dp[i] = (dp[i] + dp[i-a[j]])%MOD;
            }
        }
    }
    cout<<dp[x];
}
int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
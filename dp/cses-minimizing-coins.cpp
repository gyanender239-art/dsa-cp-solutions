//Link: https://cses.fi/problemset/task/1634

/*
Approach:
we are required to construct a sum x by using the types of coins we are given(minimum number of coins)
let us say for example we have to make 11 out of {1,5,7}. The possible ways are:
1+1+1+1+1+1+1+1+1+1+1 or 1+1+1+1+1+1+5 or 1+1+1+1+7 or 1+1+5
the minimum number of coins are used in 1+1+5 which is 3 coins
lets think from a previous number to current one. about the last number obtained before we added one of the coins.
so before we added 1 the number was 10(10+1 = 11), for 5 it was 6 (6+5 = 11) for 7 it was
4(4+7 = 11). and x = 10, x = 6, x = 4 are problems in themselves. so they are subproblems of x = 11
and lets assume they already have the optimal solutions.
for 10: it is 2(5+5)
for 6: it is 2(5+1)
for 4: it is 4(1+1+1+1)
now out of these optimal solutions of each subproblem which one can take us to 11 the fastest?
the subproblem with least answer, which is either 10 or 6(both have 2). now we just add 1 to it
let dp[i] = minimum coins used to construct i
lets consider all elements of our dp array = 1e9

now dp[x] = min(dp[x],dp[x-a[i]]+1)  (i = 0 to length of given coin array) only if x>=a[i]
base case: dp[0] = 0. because if we have to construct 1 from {1,5,7} acc to our formula
dp[1] =  min(dp[1],dp[0]+1) other coins are greater than 1
so for dp[1] to be 1 dp[0] must be 0 and also there are 0 coins which we can use to make 0

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
    vector<int> dp(x+1,1e9);
    dp[0] = 0;
    for(int i = 1;i<=x;i++){
        for(int j = 0;j<n;j++){
            if(a[j] <= i){
                dp[i] = min(dp[i],dp[i-a[j]]+1);
            }
        }
    }
    cout<<((dp[x] == 1e9)?-1:dp[x]);
}
int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
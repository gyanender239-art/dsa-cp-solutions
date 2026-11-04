//Link: https://codeforces.com/contest/1613/problem/C

//Approach: found the minimum k which can cause atleast h damage using binary search on answers
#include <bits/stdc++.h>
using namespace std;

long long f(vector<long long>&a,long long k){
    long long hp = 0;
    int size = a.size();
    for(int i = 0;i<size;i++){
        if(i != size-1){
            if(a[i]+k >= a[i+1]){
                hp+=a[i+1]-a[i];
            }
            else{
                hp+=k;
            }
        }
        else hp+=k;
    }
    return hp;
}
void solve(){
    long long n,h;
    cin>>n>>h;
    vector<long long> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    //solution
    long long l=1,r=h;
    long long k = h;
    while(l<=r){
        long long mid = l+(r-l)/2;
        if(f(a,mid)>=h){
            k = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout<<k<<"\n";
}
int main() 
{
   int t;
   cin >> t;
   while(t--){
       solve();
     
   }
    return 0;
}
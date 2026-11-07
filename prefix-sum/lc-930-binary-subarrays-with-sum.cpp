//Link: https://leetcode.com/problems/binary-subarrays-with-sum/description/

/*
Approach:
first, we build the prefix sum array. and as we know, the sum of a[L...R] (L and R inclusive) is: pref[R+1] - pref[L]

We need to find the pairs (L,R) such that:
pref[R+1] - pref[L] = goal
Or after rearranging:
pref[L] = pref[R+1] - goal

so we first insert pref[0] in the map. then for
each prefix sum pref[i] we look for pref[i] - goal
in the map.

if it exists, we add its frequency to the answer,
because each occurrence represents a valid subarray.
then we insert the current prefix sum in the
map for future.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> pref(n+1,0);
        
        for(int i = 1;i<n+1;i++){
            pref[i] = pref[i-1]+nums[i-1];
            
        }
        int ans = 0;
        unordered_map<int,int> mp;
        mp[pref[0]]++;
        for(int i = 1;i<n+1;i++){
            int val = pref[i]-goal;
            if(mp.find(val) != mp.end()){
                ans += mp[val];
            }
            mp[pref[i]]++;
        }
        return ans;
    }
};
//Link: https://leetcode.com/problems/contiguous-array/

/*
Approach:
at the start, i thought in terms of two frequency arrays of 0 and 1(p0 and p1),
we can find the frequency of 0/1 in a subarray a[L...R] by p[R+1]-p[L], for subarrays of 
equal number of 0s and 1s the condition will be p1[R+1]-p1[L] = p0[R+1]-p0[L] or rewritten as 
p1[R+1]- p0[R+1] = p1[L]-p0[L], we can reduce this to a single prefix frequency difference array
pref[i] will decrease by 1 for 0 and increase by 1 for 1. now we can just find the length of subarrays with 
equal frequencies of 0s and 1s by:- (R+1) - L where pref[R+1] = pref[L].
As we have to find the longest subarray. we have to find two values equal to each other sitting farthest
from each other. so i just iterate in the pref array, on encountering an element i ask
have i seen this element? is this in my map?
no->store in map for future with element->index
yes->update my maxlen by max(maxlen,current index - map[element])

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n+1,0);
        for(int i = 1;i<=n;i++){
            pref[i] = pref[i-1] + ((nums[i-1]==1)?1:-1);
        }
        unordered_map<int,int> mp;
        int maxlen = 0;
        for(int i = 0;i<=n;i++){
            if(mp.find(pref[i]) == mp.end()){
                mp[pref[i]] = i;
            }
            else{
                maxlen = max(maxlen,(i-mp[pref[i]]));
            }
        }
        return maxlen;
    }
};
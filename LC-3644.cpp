// Link to question: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
       if(is_sorted(nums.begin(),nums.end())){
        return 0;
       }
       int ans=INT_MAX;
       for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                ans = ans & nums[i];
            }
       }
       return ans;
    }
};
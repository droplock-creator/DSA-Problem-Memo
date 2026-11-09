// Link to question: https://leetcode.com/problems/product-of-array-except-self/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        long long pre=nums[0];
        ans[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i] = ans[i+1]*nums[i];
        }
        ans[0] = ans[1];
        for(int i=1;i<n-1;i++){
            ans[i] = ans[i+1]*pre;
            pre=pre*nums[i];
        }
        ans[n-1] = pre;
        return ans;
    }
};
// Link to question: https://leetcode.com/problems/next-greater-element-ii/


#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>St;
        vector<int>Res(nums.size(),-1);
        for (int i = 0; i < nums.size(); i++){
            while (!St.empty() && nums[St.top()] < nums[i]){
                Res[St.top()] = nums[i];
                St.pop();
            }
            St.push(i);
        }
        for (int i = 0; i < nums.size(); i++){
            while (!St.empty() && nums[St.top()] < nums[i]){
                Res[St.top()] = nums[i];
                St.pop();
            }
        }
        return Res;
        
    }
};
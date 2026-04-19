// Link to question: https://leetcode.com/problems/next-greater-element-i/description/


#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans2(nums2.size(),-1);
        vector<int> ans;
        unordered_map<int,int>Ind;
        for (int i = 0; i < nums2.size(); i++){
            Ind.insert({nums2[i],i});
        }
        stack<int>St;
        for (int i = 0; i < nums2.size(); i++){
            while (!St.empty() && nums2[St.top()] < nums2[i]){
                ans2[St.top()] = nums2[i];
                St.pop();
            }
            St.push(i);
        }
        for (int i = 0; i < nums1.size(); i++){
            auto it = Ind.find(nums1[i])->second;
            ans.push_back(ans2[it]);
        }
        return ans;
    }
};
// Link to question: https://leetcode.com/problems/rearrange-array-by-removing-distinct-values/description/

#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        multiset<int> hash;
        for(int i=0;i<nums.size();i++){
            hash.insert(nums[i]);
        }
        vector<int>ans;
        while(!hash.empty()){
            auto it = hash.begin();
            while(it != hash.end()){
                int x = *it;
                ans.push_back(x);
                it = hash.erase(it);
                while(it != hash.end() && *it==x){
                    it++;
                }
            }
        }    
        return ans;
    }
};
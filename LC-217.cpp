// Link to question: https://leetcode.com/problems/contains-duplicate/description/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto v:nums){
            if(s.find(v) != s.end()){
                return true; 
            }
            s.insert(v);
        }         
        return false;
    }
};
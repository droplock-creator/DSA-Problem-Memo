// Link to question: https://leetcode.com/problems/subsets/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> V;
        vector<int> S;
        int j = nums.size();
        int i = 0;
        Generate(nums,V,S,i,j);
        return V;
    }
    void Generate(vector<int> &n,vector<vector<int>> &a,vector<int> &b,int i,int j){
        if (i == j){
            a.push_back(b);
            return;
        }
        if (i < j){
            b.push_back(n[i]);
            Generate(n,a,b,i+1,j);
            b.pop_back();
            Generate(n,a,b,i+1,j);
        }
    }
};
// Link to question: https://leetcode.com/problems/single-number/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum=0;
        for (auto s:nums){
            sum = sum^s;
        }
        return sum; 
    }
};
// Link to question: https://leetcode.com/problems/trapping-rain-water/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> hash(n);
        int water = 0;
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
            hash[i] = max(l-height[i],0);
            if(height[i]>l){
                l=height[i];
            }
        }
        for(int i=n-1;i>=0;i--){
            hash[i] = min(hash[i],max(0,r-height[i]));
            if(height[i]>r){
                r = height[i];
            }
        }
        for(int i=0;i<n;i++){
            water = water+hash[i];
        }
        return water;
    }
};

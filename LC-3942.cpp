// Link to question: https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/description/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int a,b;
        int desc = 0;
        int asc = 0;
        for(int i=0;i<n;i++){
            if(nums[i] > nums[(i+1)%n]){
                desc++;
                a=i;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i] > nums[(i-1+n)%n]){
                asc++;
                b=i;
            }
        }
        if(is_sorted(nums.begin(),nums.end())){
            return 0;
        }
        else if(asc==0){
            return 1;
        }
        else if(desc==1){
            if(a<=n/2){
                return a+1;
            }
            else{
                return n-a+1;
            }
        }
        else if(asc==1){
            if(b<=n/2){
                return b+1;
            }
            else{
                return n-b+1; 
            }
        }
        else{
            return -1;
        }

    }
};
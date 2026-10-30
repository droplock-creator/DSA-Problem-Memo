// Link to question: https://leetcode.com/problems/single-number-ii/

// NOTE: There's better written and less complex solutions that this out there, this is just the one I wrote the first time i did this question. 


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        else{
            long long a=0;
            vector<int> bts(32);
            for(int i=0;i<nums.size();i++){
                long long ans=1;
                for(int j=0;j<32;j++){
                    if(nums[i]&ans){
                        bts[j]++;
                    }
                    ans<<=1;
                }
            }
            for(int i=0;i<32;i++){
                bts[i] = bts[i]%3;
            }
            long long ans=1;
            if(bts[31]==0){
                for(int i=0;i<32;i++){
                    a = a + bts[i]*ans;
                    ans*=2;
                }
                return int(a);
            }
            else{
                for(int i=0;i<32;i++){
                    a = a + (1-bts[i])*ans;
                    ans*=2;
                }
                return int(-1*(a+1));
            }
        }

    }
};
// Link to question: https://leetcode.com/problems/sum-of-sortable-integers/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int Ans=0;        
        for(int i=2;i<=n/2;i++){
            if(n%i==0){
                ans.push_back(i);
            }
        }
        if(n!=1){
            ans.push_back(n);
        };
        for(auto x:ans){
            bool f = true;
            int ma = 0;
            for(int i=0;i<n;i+=x){
                int desc=0;
                int mi = INT_MAX;
                int m = INT_MIN;
                for(int j=i;j<i+
                x;j++){
                    mi = min(nums[j],mi);
                    m = max(m,nums[j]);
                    if(nums[j]>nums[(j+1)%x+i]){
                        desc++;
                    }
                }
                if(ma>mi){
                    f = false;
                    break;
                }
                if(desc>1){
                    f = false;
                    break;
                }
                ma = m;
            }
            if(f){
                Ans += x;
            }
        }
        if(is_sorted(nums.begin(),nums.end())){
            Ans++;
        }
        return Ans;
    }
};
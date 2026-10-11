// Link to question: https://leetcode.com/problems/minimum-sum-of-squared-difference/description/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long total = k1+k2;
        map<int,int> f;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            f[abs(nums1[i]-nums2[i])]++;
        }
        for(auto it=f.rbegin();it!=f.rend();it++){
            if(total == 0){
                break;
            }
            if(next(it) == f.rend()){
                int b = min(total/it->second,1ll*it->first);
                total -= b*it->second;
                int c = total % it->second;
                if(b>0){
                    f[it->first-b] += it->second;
                    f[it->first] = 0;
                }
                if(c>0 && it->first-b>0){
                    f[it->first-b-1]+=c;
                    f[it->first-b]-=c;
                }
                break;
            }
            long long a = (it->first) - (next(it)->first);
            
            if( a*it->second <= total ){
                total -= a*it->second;
                f[next(it)->first] += it->second;
                f[it->first] -= it->second;
            }else{
                int b = total/it->second;
                int c = total % it->second;
                
                if(b>0){
                    f[it->first-b] += it->second;
                    f[it->first] = 0;
                }
                

                if(c>0){
                    f[(it->first)-b-1]+=c;
                    f[it->first-b]-=c;
                }
                break;

            }
        }
        total = 0;
        for(auto x:f){
            total += x.first*1ll*x.first*x.second;
        }
        return total;
    }
};
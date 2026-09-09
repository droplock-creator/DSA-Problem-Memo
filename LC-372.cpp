// Link to question: https://leetcode.com/problems/super-pow/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for(int i = 0; i < b.size()-1; i++){
            ans = binExp(ans * binExp(a,b[i],1337),10,1337);
        }
        ans = (ans * binExp(a,b[b.size()-1],1337)) % 1337;
        return ans;

    }

    int binExp(long long a, int b, int m){
        int ans = 1;
        while(b>0){
            if(b&1){
                ans = (ans*a) % m; 
            }
            a = (a*a) % m;
            b >>= 1;
        }
        return ans;
    }

};
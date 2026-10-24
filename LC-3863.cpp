// Link to question: https://leetcode.com/problems/minimum-operations-to-sort-a-string/description/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        vector<int>hash(26,0);
        char ma='a';
        char mi='z';
        for(int i=0;i<n;i++){
            if(s[i] > ma){
                ma = s[i];
            }
            if(s[i] < mi){
                mi = s[i];
            }
            hash[s[i]-'a']++;
        }
        if(!is_sorted(s.begin(),s.end()) && n==2){
            return -1;
        }
        else if(is_sorted(s.begin(),s.end())){
            return 0;
        }
        else if(s[0] == mi || s[n-1] == ma){
            return 1;
        }
        else if(s[0] == ma && s[n-1] == mi && hash[ma-'a']==1 && hash[mi-'a']==1){
            return 3;
        }else{
            return 2;
        }
    }
};
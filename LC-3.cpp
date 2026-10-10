// Link to question: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        string sr="";
        for(int i=0;i<s.size();i++){
            if(sr.find(s[i]) == string::npos){
                sr+=s[i];
            }else{
                ans = max(ans,int(sr.size()));
                sr.erase(0,sr.find(s[i])+1);
                sr+=s[i];
            }
        }
        return max(ans,int(sr.size()));
    }
};
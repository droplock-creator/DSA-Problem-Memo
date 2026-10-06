// Link to question: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

#include<iostream>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int o=0;
        int c=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                o++;
            }
            else if(c+1>o){
                ans++;
                continue;
            }
            else{
                c++;
            }

        }
        o=0;
        c=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == ')'){
                c++;
            }
            else if(o+1>c){
                ans++;
                continue;
            }
            else{
                o++;
            }
        }
        return ans;
    }
};

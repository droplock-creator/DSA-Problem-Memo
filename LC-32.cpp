// Link to question: https://leetcode.com/problems/longest-valid-parentheses/description/

#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int ct=0;
        string st ="";
        int i=0,j=0;
        for(int k=0;k<s.size();k++){
            if(s[k] == ')' && j+1 > i){
                j = 0;
                i = 0;
                st = "";
                continue;
            }
            if(s[k] == '('){
                i++;
                st.push_back('(');
            }else{
                j++;
                st.push_back(')');
            }
            if(i==j){
                ct = max(ct,i+j);
            }
        }
        if(i!=j){
            i=0;j=0;
            for(int k=st.size()-1;k>=0;k--){
                if(st[k] == ')'){
                    j++;
                }else{
                    i++;
                }
                if(i==j){
                    ct = max(ct,i+j);
                }
                if(i>j){
                    i=0;
                    j=0;
                    continue;
                }
            }
        }
        return ct;
    }
};
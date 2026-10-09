// Link to question: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/

#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int ins=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push('(');
            }
            else{
                if(i+1 < s.size() && s[i+1]==')'){
                    i++;
                }
                else{
                    ins++;
                }
                if(st.empty()){
                    ins++;
                }
                else{
                    st.pop();
                }
            }
        }
        if(!st.empty()){
            ins+= st.size()*2;
        }
        return ins;
    }
};
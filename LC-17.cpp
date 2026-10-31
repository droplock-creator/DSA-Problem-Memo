// Link to question: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> d(10);
        vector<string> s;
        char c='a';
        for(int i=2;i<=9;i++){
            for(int j=0;j<=2;j++){
                d[i].push_back(c++);
            }
            if(i==7 || i==9){
                d[i].push_back(c++);
            }
        }
        generate(digits,s,0,d,"");
        return s;
    }

    void generate(string &digits,vector<string> &s,int i, vector<vector<char>> &d,string st){
        if(i==digits.size()){
            s.push_back(st);
            return;
        }
        for(auto x:d[digits[i]-'0']){
            st.push_back(x);
            generate(digits,s,i+1,d,st);
            st.pop_back();
        }
    }
};
// Link to question: https://leetcode.com/problems/score-of-parentheses/description/

#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        bool cls=false;
        stack<char>p;
        int score=0;
        for(int i=0;i<s.size();i++){
            if( s[i] == '(' ){
                p.push('(');
                cls=false;
            }
            else if( s[i] == ')' ){
                if(cls){
                    p.pop(); 
                }else{
                    score += (1<<(p.size()-1))*1;
                    p.pop();
                    cls=true; 
                }
            }
        }
        return score;
    }
};
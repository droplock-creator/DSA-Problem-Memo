// Link to question: https://leetcode.com/problems/valid-parenthesis-string/description/

#include<iostream>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int star=0;
        int open=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                open++;
            }
            else if(s[i] == '*'){
                star++;
            }
            else{
                if(open>0){
                    open--;
                }
                else if(star>0){
                    star--;
                }
                else{
                    return false;
                }
            }
        }

        open=0;
        star=0;
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == ')'){
                open++;
            }
            else if(s[i] == '*'){
                star++;
            }
            else{
                if(open>0){
                    open--;
                }
                else if(star>0){
                    star--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
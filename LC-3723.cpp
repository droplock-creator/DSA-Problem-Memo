// Link to question: https://leetcode.com/problems/maximize-sum-of-squares-of-digits/

#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num){
            return "";
        }
        string s="";
        for(int i=0;i<sum/9;i++){
            s+='9';
        }
        if(sum%9!=0){
            s+=to_string(sum%9);
        }
        for(int i=s.size();i<num;i++){
            s+='0';
        }
        return s;

    }
};
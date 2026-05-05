// Link to question: https://leetcode.com/problems/k-th-symbol-in-grammar/description/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    int kthGrammar(int n, int k) {
        string s; 
        if (n == 1){
            return 0;
        }
        Generate(s,n,k);
        return stoi(s);
    }
    void Generate(string &s,int n,int k){
        if (n == 2){
            (k == 2) ? s = "1":s = "0";
            return;
        }
        Generate(s,n-1,(k+1)/2);
        if (k % 2 == 0) {s = to_string(1-stoi(s));} 
    }
};
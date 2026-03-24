// GOAL PARSER

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string interpret(string command) {
        string res;
        for(int i=0;i<command.size();i++){
            if((command[i]=='(') && (command[i+1]==')')){
                res=res+'o';
                i++;
            }
            else if((command[i]=='(') && (command[i+1]=='a')){
                res=res+"al";
                i=i+3;
            }
            else{res=res+'G';}
        }
        return res;
    }
};

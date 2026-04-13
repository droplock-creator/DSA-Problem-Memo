// Link to question: https://www.geeksforgeeks.org/problems/twice-counter4236/1


#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
  public:
    int countWords(string list[], int n) {
        int ct = 0;
        unordered_map<string,int> s;
        
        for (int  i = 0; i < n; i++){
            if ( s.find(list[i]) != s.end() ){
                s[list[i]]++;
            }
            else{s.insert({list[i],1});}
        }
        for (auto m:s){
            if (m.second == 2){
                ct++;
            }
        }
        return ct;
        
    }
};
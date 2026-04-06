// Link to question: https://leetcode.com/problems/permutation-in-string/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {return false;}
        vector<int>H1(26,0);
        vector<int>H2(26,0);
        
        for (int i = 0; i < s1.size(); i++){
             H1[s1[i]-'a']++;
        }
        for (int i = 0; i < s1.size(); i++){
            H2[s2[i]-'a']++;
        }
        if (H2==H1) {return true;}
        for (int i = s1.size(); i< s2.size(); i++){
            H2[s2[i-s1.size()]-'a']--;
            H2[s2[i]-'a']++;
            if(H2==H1) {return true;}
        }
        return false;



    }
};
// Link to question: https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> H1(26,0);
        vector<int> H2(26,0);
        vector<int> Num;
        if (p.size() > s.size()) {return Num;}
        for (int  i = 0; i < p.size(); i++){
            H1[p[i]-'a']++;
        }
        for (int i = 0; i < p.size(); i++){
            H2[s[i]-'a']++;
        }
        if (H2==H1) {Num.push_back(0);}
        for (int i = p.size(); i < s.size(); i++){
            H2[s[i-p.size()]-'a']--;
            H2[s[i]-'a']++;
            if(H2==H1) {Num.push_back(i-p.size()+1);}
        }
        return Num;
    }
};
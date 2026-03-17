//Remove characters from first string that are present in second string.First is always larger than second.1<=str<=50
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
  public:
    string removeChars(string str1, string str2) {
        string s;
        int l1=str1.size();
        int l2=str2.size();
        vector<int>hash(26,0);
        for(int i=0;i<l2;i++){
            hash[int(str2[i])-97]++;
        }
        for(int i=0;i<l1;i++){
            if(hash[int(str1[i])-97]==0){
                s=s+str1[i];
            }
        }
        return s;
    }
};


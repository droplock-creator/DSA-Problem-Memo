// Link to question: https://www.geeksforgeeks.org/problems/in-first-but-second5423/1

#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {

  public:
    vector<int> findMissing(vector<int>& a, vector<int>& b) {
        int s1 = b.size();
        int s2 = a.size();
        vector <int> ct(1e5+5,0);
        vector <int>mis;
        for (int i = 0; i < s1; i++){
            ct [b[i]]++;
        }
        for (int i = 0; i < s2; i++){
            if (ct[a[i]] == 0){
                mis.push_back(a[i]);
            }
        }
        return mis;
        
    }
};

//  **NOTE: Use Sets or Unordered_set
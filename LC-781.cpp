// Link to question: https://leetcode.com/problems/rabbits-in-forest/description/

#include<iostream>
#include<vector>   
using namespace std;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int>ct(1000,0);
        for (int i = 0; i < answers.size(); i++){
            if(ct[answers[i]] == 0){
                ct[answers[i]]+=answers[i];
            }
            else{
                ct[answers[i]]--;
            }
        }
        int count = answers.size();
        for (auto v:ct){
            count+=v;
        }
        return count;
    }
}; 
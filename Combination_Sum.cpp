// Link to question: https://www.geeksforgeeks.org/problems/combination-sum-1587115620/1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        vector<vector<int>> Ans;
        vector<int> Sub;
        sort(arr.begin(),arr.end());
        Generate(Ans,arr,target,Sub,0);
        return Ans;
        
    }
    void Generate(vector<vector<int>> &a,vector<int> &arr,int t,vector<int> &b,int ind){
        if (t == 0){
            a.push_back(b);
            return;
        }
        for (int i = ind; i < arr.size(); i++){
            if (i > ind && arr[i] == arr[i-1]){
                continue;
            }
            if (arr[i] <= t){
                b.push_back(arr[i]);
                Generate(a,arr,t-arr[i],b,i);
                b.pop_back();
            }
        }
    }
};
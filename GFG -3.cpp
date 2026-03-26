// Link to question: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int size = arr.size();
        int sum = 0;
        for (int i = 0; i < k; i++){
            sum += arr[i];
        }
        int maxsum = sum;
        for (int i = k; i < size; i++){
            sum = sum + arr[i] - arr[i-k];
            maxsum = max(maxsum,sum);
        }
        return maxsum;
    } 
};
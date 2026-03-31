// Link to question: https://www.hackerrank.com/challenges/crush/problem

#include<iostream>
#include<vector>    
using namespace std;
long arrayManipulation(int n, vector<vector<int>> queries) {
    long maxi;
    vector<long> Nums(n+5,0);
    for (int i = 0; i < queries.size(); i++){
       Nums[queries[i][0]] += queries[i][2];  
       Nums[queries[i][1]+1] -= queries[i][2];  
    }
    for (int i = 1; i < n+1; i++){
        Nums[i] += Nums[i-1]; 
    }
    maxi = *max_element(Nums.begin()+1,Nums.begin()+n+1);
    return maxi;
} 
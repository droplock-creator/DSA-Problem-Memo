// Link to question: https://leetcode.com/problems/count-primes/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        vector<bool> sieve(n,true);
        int ct=1;
        for(int i = 3; i*i < sieve.size();i+=2){
            if(sieve[i] == true){
                for(int j=i*i; j<sieve.size();j+=2*i){
                    if(sieve[j] == true){
                        sieve[j] = false;
                    }
                }
            }
        }
        for(int i=3; i<n; i+=2){
            if(sieve[i] == true){
                ct++;
            }
        }
        return ct;   
    }
};
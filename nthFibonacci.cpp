// Link to question: https://www.geeksforgeeks.org/problems/nth-fibonacci-number1335/1

#include<iostream>
using namespace std;
class Solution {
  public:
    int nthFibonacci(int n) {
        if (n==0) {return 0;}
        if (n==1) {return 1;}
        return nthFibonacci(n-1) + nthFibonacci(n-2);
    }
};
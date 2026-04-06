// Link to question: https://www.geeksforgeeks.org/problems/josephus-problem/1

#include<iostream>
using namespace std;
class Solution {
  public:
    int josephus(int n, int k) {
        if(n==1){
            return 1;
        }
        else if((josephus(n-1,k)+k)%n==0){
            return n;
        }
        else{
            return(josephus(n-1,k)+k)%n;
        }
    }
};
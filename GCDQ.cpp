/*

You are given an array A of integers of size N. You will be given Q queries where
each query is represented by two integers L, R. You have to find the gcd(Greatest
Common Divisor) of the array after excluding the part from range L to R inclusive
(1 Based indexing). You are guaranteed that after excluding the part of the array
remaining array is non empty.

Input

. First line of input contains an integer T denoting number of test cases.
· For each test case, first line will contain two space separated integers N, Q.
. Next line contains N space separated integers denoting array A.
. For next Q lines, each line will contain a query denoted by two space
  separated integers L, R.

Constraints

Subtask #1: 40 points

. 2 ≤ T, N ≤ 100,1 ≤ Q ≤ N,1 <= A[i] ≤ 10^5
. 1 <= L, R ≤ N and L ≤ R

Subtask #2: 60 points

. 2 ≤ T, N ≤ 10^5, 1 ≤ Q ≤ N,1 ≤ A[i] ≤ 10^5
. 1 <= L, R ≤ N and L ≤ R
. Sum of N over all the test cases will be less than or equal to 10^6. 
  
*/
 
#include<iostream>
#include<vector>    
using namespace std;
int gcd(int a,int b){
    while (b != 0){
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n,q,G;
        cin >> n >> q;
        vector <int>Nums(n+5,0);
        vector<int> GcdF(n+5,0);
        vector<int> GcdB(n+5,0);
        for (int i = 1; i < n+1; i++){
            cin >> Nums[i];
        }
        GcdF[1]=Nums[1];
        GcdB[n]=Nums[n];
        for (int i = 2; i < n+1; i++){
            GcdF[i] = gcd(Nums[i],GcdF[i-1]);
        }
        for (int i = n-1; i >= 1; i--){
            GcdB[i] = gcd(Nums[i],GcdB[i+1]);
        }
        while (q--){
            int l,r;
            cin >> l >> r;
            G = gcd(GcdF[l-1],GcdB[r+1]);
            cout << G <<endl;
        }
    }
}

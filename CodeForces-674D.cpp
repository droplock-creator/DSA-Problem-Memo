// Link to question: https://codeforces.com/contest/1426/problem/D

#include<iostream>
#include<vector>    
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>Num(n,0);
    for (int i = 0; i < n; i++){
        cin >> Num[i];
    }
    vector<long long>Psum(n+5,0);
    for (int i = 1; i < n; i++){
        Psum[i] = Psum[i-1]+Num[i-1];
    }
}    
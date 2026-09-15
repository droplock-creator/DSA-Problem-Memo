// Lint to question: https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/happy-and-sets/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long M = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long ans=1;
    cin >> n;
    vector<int> Num(n,0);
    for(int i=0;i<n;i++){
        cin >> Num[i];
        ans = (ans*(Num[i]+1)) % M;
    }
    cout << (ans-1+M) % M;

}
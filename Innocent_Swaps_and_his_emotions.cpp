// Link to question: https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/innocent-swaps-and-his-emotions-1/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long binExp(long long a, long long b, long long M){
    long long ans= 1;
    while(b > 0){
        if(b&1){
            ans = (ans*a) % M;
        }
        b >>= 1;
        a = (a*a) % M;
    }
    return ans;
}

long long M = 1000000007;

int main() {
    int t;
    cin >> t;

    vector<long long> factorial(1e6+2);
    factorial[0] = 1;
    for(int i = 1; i < factorial.size(); i++){
        factorial[i] = (factorial[i-1] * (i % M) ) % M;
    }

    while(t--){
        int n,k;
        cin >> n >> k;
        long long a = binExp(2,k,M);
        long long b = ( factorial[n] * binExp((factorial[k]*factorial[n-k])%M,M-2,M) ) % M;
        cout << (a*b) % M << endl;
    }
}
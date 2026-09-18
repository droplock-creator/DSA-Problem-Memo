// Link to question: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long M = 1000000007;
long long binExp(long long a,long long b){
    long long ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans*a) % M;
        }
        b>>=1;
        a = (a*a)%M;
    }
    return ans;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<long long> fact(k+1,0);
        fact[0] = 1;
        for(int i = 1; i<fact.size();i++){
            fact[i] = (fact[i-1] * i) % M;
        }
        long long ans = ( fact[k] * binExp(fact[k-n],M-2) ) % M;
        cout << ans << endl;

    }
}
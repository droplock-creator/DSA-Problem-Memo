// Link to question: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/diedie/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long M = 1000000007;

long long binExp(long long a,long long b, long long M){
    long long ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans*a)% M;
        }
        b>>=1;
        a = (a*a) % M;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        long long ans = 1;
        ans = ( ans * ( 2*binExp(binExp(2,n,M),M-2,M) ) ) % M;
        cout << ans << endl;
    }
}
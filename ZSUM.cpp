// Link to question: https://www.spoj.com/problems/ZSUM/

#include<iostream>
#include<vector>

using namespace std;

long long binExp(long long a, long long b,long long m){
    long long ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans*a) % m;
        }
        a = (a*a) % m;
        b >>= 1;
    }
    return ans;
}

int m = 10000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        int n,k;
        cin >> n >> k;
        if(n==0 && k==0){
            break;
        }
        long long ans = 0;
        ans += ((binExp(n,k,m) + binExp(n,n,m))%m + ( (2*binExp(n-1,k,m)) % m + (2*binExp(n-1,n-1,m)) % m )%m) % m ;
        cout << ans << endl;
    }
}
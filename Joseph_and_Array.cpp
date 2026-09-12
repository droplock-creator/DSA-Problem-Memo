// Link to question: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/joseph-and-arrayaugclash/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

long long binExp(long long a, long long b, long long M){
    long long ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans*a) % M;
        }
        a = (a*a) % M;
        b >>= 1;
    } 
    return ans;
}

vector<int> sieve(1000008,1);

long long M =1000000007;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve[0] = sieve[1] = 0;
    for(int i = 2; i*i < sieve.size();i++){
        if(sieve[i] == 1){
            sieve[i] = i;
            for(int j = i*i; j < sieve.size(); j+=i){
                if(sieve[j] == 1){
                    sieve[j] = i;
                }
            }
        }
    }

    for(int i = 2; i< sieve.size(); i++){
        if(sieve[i] == 1){
            sieve[i] = i;
        }
    }

    vector<long long> Fact(2000002);
    Fact[0] = 1;
    for(int i = 1; i < Fact.size(); i++){
        Fact[i] = (Fact[i-1]*i) % M;
    }
    unordered_map<int,int>facto;
    int n,k,a;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a;
        while(a>1){
            facto[sieve[a]]++;
            a = a/sieve[a];
        }
    }
    long long ans = 1;
    for(auto x:facto){
        long long ways = ( Fact[x.second + k - 1] * binExp(((Fact[k-1]*Fact[x.second]) % M),M-2,M) )%M;
        ans = (ans * ways) % M;
    }
    cout << ans << endl;
    
}
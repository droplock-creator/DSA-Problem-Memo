// Link to question: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/
 
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<unordered_map>
 
using namespace std;
 
vector<int> sieve(1000001,1);
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    sieve[0] = 0; sieve[1] = 1;
    for(int i = 2; i < sieve.size();i++){
        if(sieve[i] == 1){
            sieve[i] = i;
            for(int j = 2*i; j<sieve.size(); j+=i){
                if(sieve[j] == 1){
                    sieve[j] = i;
                }
            }
        }
    }
    int n,q;
    long long p=1;
    cin >> n >> q;
    
    vector<int> A(n,0);
    vector<bool>powers(1000001,false);
    for(int i=0; i < n; i++){
        cin >> A[i];
    }
    for(int i=0;i<A.size();i++){
        if(A[i] == 0 || A[i] == 1){
            continue;
        }
        while(true){
            p = p*A[i];
            if(p>1000000){
                break;
            }else{
                powers[p] = true;;
            }
        }
        p=1;
    }
 
 
    while(q--){
        int x,c,ct=0;
        cin >> x;
        c = x;
        if(sieve[x] == x){
            cout << "NO" << endl;
        }
        else{
            int prime[8];
            int exponents[8];
            int cnt = 0;
 
            while(c > 1){
                int p = sieve[c];
 
            int e = 0;
            while(c % p == 0){
                c /= p;
                e++;
            }
        
            prime[cnt] = p;
            exponents[cnt] = e;
            cnt++;
            }
            for(int i=0;i<cnt;i++){
                for(int j=i;j<cnt;j++){
                    if(i==j && exponents[i] < 2){
                        continue;
                    }
 
                    int y = x/(prime[i]*prime[j]);
                    if(powers[y] == true || y==1){
                        ct++;
                    }
                }
            }
            if(ct==0){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }
    }
}
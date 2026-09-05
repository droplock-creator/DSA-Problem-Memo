// Link to question: https://www.hackerearth.com/problem/algorithm/ross-and-unagi-2/

#include<iostream>
#include<vector>

using namespace std;

long long binExp(long long a, long long b, int m){
    long long ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans*a) % m;
        }
        a = (a*a) % m;
        b = b >> 1;
    }
    return ans;
}

int m = 1000003;
vector<int> sieve(1e6+3,1);

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < sieve.size(); i++) {
        sieve[i] = i;
    }

    sieve[0] = sieve[1] = 0;
    for(int i = 2; i*i < sieve.size(); i++){
        if(sieve[i] == i){
            for(int j = i*i; j < sieve.size(); j+=i){
                if(sieve[j] == j){
                    sieve[j] = i;
                }
            }
        }
    }

    int q;
    cin >> q;
    while(q--){
        int a,b;
        long long c;
        cin >> a >> b >> c;
        if(a % m == 0){
            if( b == 0 && c > 0){
                a = 2;
            }else{
                a = 1;
            }
        }
        else{
            b = binExp(b,c,1000002);
            a = binExp(a,b,m);
            a = (a+1) % m;  
        }
        b = 0;
        while(a > 1){
            b += sieve[a];
            a = a/sieve[a];
        }
        cout << b << '\n';
    }

}

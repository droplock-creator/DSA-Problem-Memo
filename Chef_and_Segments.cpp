// Link to question: https://www.codechef.com/problems/CHMOD

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

vector<int> sieve(101,1);
unordered_map<int,int>Prime;

long long binExp(long long a, int b, int M){
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


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    sieve[0] = sieve[1] = 0;
    for(int i=2; i*i < sieve.size(); i++){
        if(sieve[i] == 1){
            for(int j = i*i; j < sieve.size(); j+=i){
                sieve[j] = i;
            }
        }
    }

    int a = 0;

    for(int i=0; i < sieve.size(); i++){
        if(sieve[i] == 1){
            sieve[i] = i;
            Prime[i] = a++;
        }
    }

    int n,t;
    cin >> n;
    vector<int> A(n,0);
    vector<vector<int>> B(n,vector<int>(25,0));

    for(int i=0; i < n; i++){
        cin >> A[i];
    }

    for(int i = 0; i < n; i++){
        if(i > 0){
            for(int j = 0; j < 25; j++){
                B[i][j] = B[i-1][j];
            }
        }
        int a = A[i];
        while(a > 1){
            B[i][Prime[sieve[a]]]++;
            a = a/sieve[a];
        }
    }

    cin>>t;
    while(t--){
        int L,R,M;
        cin >> L >> R >> M;
        L--; 
        R--;
        long long ans = 1;
        for(auto x:Prime){
            ans =  (ans*binExp(x.first,B[R][x.second] - ((L == 0) ? 0:B[L-1][x.second]),M)) % M;
        }
        cout << ans << endl;
    }
}

// Link to question: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/panda-and-chain-reaction/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int M = 1000003;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    vector<long long> fact(1000004,0);
    fact[0] = 1;
    for(int i = 1; i < fact.size(); i++){
        fact[i] = (fact[i-1] * (i%M)) % M;
    }
    
    while(t--){
        long long N,X;
        cin >> N >> X;
        if(N > 1000003){
            cout << 0 << endl;
        }else{
            cout << (fact[N] * (X%M))%M << endl;
        }
    }

}
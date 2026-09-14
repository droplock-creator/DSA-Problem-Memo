// Link to question: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/the-confused-monk/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int a,int b){
    if(a ==0){
        return b;
    }
    return gcd(b%a,a);
}

long long binExp(long long a, int b, long long M){
    long long ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans*a) % M;
        }
        b>>=1;
        a = (a*a) % M;
    }
    return ans;
}

long long M = 1000000007; 

int main(){
    int n,g=0;
    long long f=1;
    cin >> n;
    vector<int> Num(n);
    for(int i=0; i<n; i++){
        cin >> Num[i];
        f = (f*Num[i] ) % M;
        g = gcd(g,Num[i]); 
    }
    cout << binExp(f,g,M);

}
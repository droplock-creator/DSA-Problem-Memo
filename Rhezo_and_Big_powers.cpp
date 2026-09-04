// Link to question: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/rhezo-and-big-powers-1/

#include<iostream>
#include<string>
#include<algorithm>

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

int main(){
    int a,c=0;
    long long e = 1;
    cin >> a;
    string b; 
    cin >> b;
    for(int i = b.size()-1; i >= 0; i--){
        c = (c + ((e*((b[i] -'0') % 1000000006)) % 1000000006)) % 1000000006;
        e = (e*10) % 1000000006;
    }
    cout << binExp(a,c,1000000007);

}
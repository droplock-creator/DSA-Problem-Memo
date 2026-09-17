// Link to question: https://codeforces.com/contest/776/problem/B

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n>=3){
        cout << 2 << endl;
    }
    else{
        cout << 1 << endl;
    }
    vector<bool> sieve(n+2,true);
    sieve[0] = sieve[1] = false;
    for(int i = 3; i*i <sieve.size();i+=2){
        if(sieve[i] == true){
            for(int j=i*i; j<sieve.size(); j+=2*i){
                sieve[j] = false;
            }
        }
    }
    cout << 1 <<" ";
    for(int i=3;i<sieve.size();i++){
        if(sieve[i] == false || i%2==0){
            cout<<2<<" ";
        }
        else{
            cout<<1<<" ";
        }
    }

}
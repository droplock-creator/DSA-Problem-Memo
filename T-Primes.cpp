// Link to question: https://codeforces.com/problemset/problem/230/B

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int n;
    long long nm,s;
    cin >> n;
    vector<bool>num(1e6+1,true);
    num[0] = num[1] = false;
    for(int i = 2; i*i <= 1e6; i++){
        if(num[i]){
            for(int j = i*i; j <= 1e6; j += i){
                num[j] = false;
            }
        }
    }
    for(int i = 0; i <n; i++){
        cin >> nm;
        s = sqrt(nm);
        if(s*s == nm && num[s]){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}
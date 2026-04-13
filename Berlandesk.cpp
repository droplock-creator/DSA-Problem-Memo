// Link to question: https://codeforces.com/problemset/problem/4/C

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin >> n;
    unordered_map<string,int> m;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        m[s]++;
        if (m[s] == 1){
            cout << "OK" << endl;
        }
        else{
            cout << s << m[s]-1 << endl;
        }
    }
}
// Link to question: https://codeforces.com/problemset/problem/525/A

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    int n,ct=0;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char,int> m;
    for (int i = 1; i <= 2*n-2; i++){
        if (i % 2 != 0){
            if (m.find(s[i-1]) != m.end()){
                m[s[i-1]]++;
            }
            else{
                m.insert({s[i-1],1});
            }
        }
        else{
            if (m.find(s[i-1]-'A'+'a') != m.end()){
                m[s[i-1]-'A'+'a']--;
            }
            else{
                ct++;
            }
        }
    }
    cout << ct << endl;
}
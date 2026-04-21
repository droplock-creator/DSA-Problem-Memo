// Link to question: https://www.hackerearth.com/problem/algorithm/stl/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool swapCase(pair<string,int> a, pair<string,int> b){
    if (a.second != b.second){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(){
    int n,m;
    string s;
    cin >> n;
    vector<pair<string,int>> J;
    for (int i = 0; i < n; i++) {
        cin >> s >> m;
        J.push_back({s,m});
    }
    sort(J.begin(),J.end(),swapCase);
    for (auto v:J){
        cout << v.first << " " << v.second << endl;
    }
}
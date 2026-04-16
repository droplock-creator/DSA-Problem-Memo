// Link to question: https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/?fbclid=IwAR09BMLG-1NhqDlVQq0KIzSr8ZTgqrbJmdfnsXc7KnDiphgX5UmbFLoEYjE


// #include <bits/stdc++.h>
#include <utility>
#include <string>
#include<set>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   int n,m;
   string s;
   cin >> n;
   multiset<pair<int,string>>M;
   for (int i = 0; i < n; i++){
      cin >> s >> m;
      M.insert({-m,s});
   }
   for (auto v:M){
      cout << v.second << " " << -v.first << endl;
   }
}

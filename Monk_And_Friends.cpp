// Link to question: https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/?fbclid=IwAR1n1FJUNpWIeq7dHY-HytoqqE1nbK9gD4jMjI2UWGTPE8GF4kHROCb7ouA


#include <iostream>
#include <string>
#include <unordered_set>
// #include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n,m;
        long long k;
        cin >> n >> m;
        unordered_set<long long>St;
        for (int i = 0; i < n; i++){
            cin >> k;
            St.insert(k);
        }
        for (int i = 0; i < m; i++){
            cin >> k;
            if (St.find(k) == St.end()){
                cout << "NO" << endl;
                St.insert(k);
            }
            else{
                cout << "YES" << endl;

            }
        }
    }
}

// Link to question: https://www.hackerearth.com/problem/algorithm/monks-birthday-party/?fbclid=IwAR3COuGp9LqoHKWOnfS-duVdKrF0Vx5shbCbGeiWqSgkdoA2z9926vNy5Ew


#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n;
        set<string>In;
        for (int i = 0; i < n ; i++){
            cin >> s;
            if (In.find(s) != In.end()){
                continue;
            }
            In.insert(s);
        }
        for (auto v:In){
            cout << v << endl;
        }
    }
}

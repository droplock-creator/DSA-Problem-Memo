// Link to question: https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/little-jhool-and-the-magical-jewels/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        string s1="ruby";
        vector<int> count(4,0);
        for (int i = 0; i < s.size(); i++){
            int idx = s1.find (s[i]);
            if (idx != string::npos){
                count[idx]++;
            }
        }
        cout << *min_element(count.begin(),count.end()) << endl;
    }
}
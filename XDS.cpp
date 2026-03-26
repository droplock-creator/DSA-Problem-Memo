//  Link to question: https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/xsquare-and-double-strings-1/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        int flag=0;
        cin >> s;
        vector<int> F(26,0);
        for (int i = 0; i < s.size(); i++){
            F[s[i]-'a']++;
        }
        for (int i = 0; i < 26; i++){
            if(F[i] >= 2){
                flag++;
                break;
            }
        }
        (flag == 0) ? cout << "No" <<endl:cout << "Yes" <<endl;
    }
}

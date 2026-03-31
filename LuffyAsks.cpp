/*

Luffy with his crew is on the way to Dressrosa, where he will belfighting one of the warlords of the sea Doflamingo. But now
he is getting bored and wants do a fun activity. He is very much obsessed with palindromes. Given a string S of lower case
English alphabet of length N and two Integers L and R he wants to know whether all the letters of the substring from index L
to R (L and R included) can be rearranged to form a palindrome or not. He wants to know this for Q values of L and R and
needs your help in finding the answer.
Palindrome is a string of characters which when reversed reads same as the original String.

CONSTRAINTS :

1 ≤ t ≤ 10

1 ≤ N, Q ≤ 100000

1≤ L ≤ R ≤ N

'a' ≤ S[i] ≤'z' for 1 ≤ i ≤ N

INPUT :
First line contains an integer t denoting the number of test cases
First line of each test case contains 2 space separated integers N and Q, the length of the string and number of queries
respectively
Next line contains the string S
Each of the Next Q lines contain 2 space separated integers L and R

OUTPUT :
For each query of each test case print "YES" if true else if without palindrome output "NO" in new line

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<vector<int>> Count(n+1,vector<int>(26,0));
        Count[1][s[0]-'a']++;
        for (int i = 2; i < n+1; i++){
            Count[i] = Count[i-1];
            Count[i][s[i-1]-'a']++;
        }
        while(q--){
            int l,r,ct=0;
            cin >> l >> r;
            for (int  i = 0; i < 26; i++){
                if ( (Count[r][i]-Count[l-1][i]) % 2 !=0 ){
                    ct++;
                }
            }
            if (ct > 1) {cout << "NO" <<endl; }
            else{cout << "YES" <<endl;}
        }
    }
}
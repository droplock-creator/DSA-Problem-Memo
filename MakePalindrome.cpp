// Hackerrank: Make Palindrome

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        vector<int>h(26,0);
        int n,ct=0;
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++){
            h[s[i]-'a']++;
        }
        for(int i=0;i<h.size();i++){
            if(h[i]%2!=0){
                ct++;
            }
        }
        (n%2==0)?cout<<--ct<<endl:cout<<max(1,--ct)<<endl;
    }
}



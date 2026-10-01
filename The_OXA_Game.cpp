#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,o=-1,prev;
        string s,s1;
        cin >> s;
        cin >> n;
        vector<int> oxa(1<<n,-1);
        vector<int> nums(n,0);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        for(int i=1; i<(1<<n); i++){
            if(__builtin_popcount(i) == 1){
                oxa[i] = nums[__builtin_ctz(i)];
                o = max(o,oxa[i]);
                prev = i;
            }
            else{
                int a = i^prev;
                if(__builtin_popcount(a) %3 == 0){
                    oxa[i] = oxa[a] + nums[__builtin_ctz(prev)];
                     
                }
                else if(__builtin_popcount(a)%3==1){
                    oxa[i] = oxa[a] | nums[__builtin_ctz(prev)];
                }
                else{
                    oxa[i] = oxa[a] ^ nums[__builtin_ctz(prev)];
                }
                o = max(o,oxa[i]);
            }
        }

        if(o&1){
            s1="Odd";
        }else{
            s1 = "Even";
        }

        if(s==s1){
            cout << "Monk" << "\n";
        }else{
            cout << "Mariam" << "\n";
        }
    }
}
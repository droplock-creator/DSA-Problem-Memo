// Link to question: https://www.spoj.com/problems/AGGRCOW/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isValid(vector<int> &s, long long mid, int k){
    int start = s[0];
    for(int i = 1; i < (int)s.size(); i++ ){
        if(s[i] - start >= mid){
            start = s[i];
            k--;
        }
        if(k == 0){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,c;
        cin >> n >> c;
        vector<int> stall(n,0);
        for( int i = 0; i < n; i++){
            cin >> stall[i];
        }
        sort(stall.begin(), stall.end());
        long long low = 1, high = stall[n-1] - stall[0], ans = 0;
        while(high-low > 1){
            ans = (high+low)/2;
            if(isValid(stall,ans,c-1)){
                low = ans;
            }
            else{
                high = ans - 1;
            }
        }
        if(isValid(stall,high,c-1)){
            cout << high << endl;
        }
        else{
            cout << low << endl;
        }
    }

}
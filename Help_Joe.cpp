// Link to question: https://www.hackerearth.com/problem/algorithm/help-joe-ii/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<long long> num(n,0);
    for(int i = 0; i < n; i++){
        cin >> num[i];
        num[i] = num[i] % m;
    }
    sort(num.begin(),num.end());
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        x = x % m;
        if( x == 0){
            cout << num[n-1] << endl; 
            continue;
        }
        if( x == m-1){
            if(num[0] == 0){
                cout << m-1 << endl;
            }
            else{
                cout << (m-1 + num[n-1])%m << endl;
            }
            continue;
        }
        int low=0, high=n-1;
        while(high != low){
            int mid = (low + high) / 2;
            if(num[mid] + x < m){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        if(low == 0){
            cout << (x+num[n-1]) % m << endl;
        }
        else{
            cout << max(x+num[low-1],(x+num[n-1])%m) << endl;
        }

    }
}
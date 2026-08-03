// Link to question: https://codeforces.com/problemset/problem/1462/D

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int t;
    cin >> t;
    while (t--){
        int n,sum=0,div;
        cin >> n;
        vector<int> num(n,0);
        for (int i = 0; i < n; i++){
            cin >> num[i];
            sum += num[i];
        }
        for(int j = n; j > 0; j--){
            if(sum % j == 0){
                div = sum/j;
                int s = 0;

                for(int i = 0; i < n; i++){
                    s = s+num[i];
                    if(s == div){
                        s = 0;
                    }
                    else if(s > div){
                        break;
                    }
                }
                if(s == 0){
                    cout << n-j <<endl;
                    break;
                }
            }
        }
    }
}
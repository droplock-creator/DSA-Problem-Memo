// Link to question: https://www.spoj.com/problems/MOZSATLA/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int>Num(n-1,0);
        vector<int>Arr(n,0);
        for (int i = 0; i < n-1; i++){
            cin >> Num[i];
        }
        Arr[0] = 0;
        for (int i = 1; i < n; i++){
            if (Num[i-1] == 0){
                Arr[i] = Arr[i-1];
            }
            else if (Num[i-1] == 1){
                Arr[i] = Arr[i-1] + 1;
            }
            else{
                Arr[i] = Arr[i-1] - 1;
            } 
        }
        int shift = 1 - *min_element(Arr.begin(),Arr.end());
        for (int i = 0; i < n; i++){
            cout << Arr[i] + shift << " ";
        }
        cout << "\n";
    }
}
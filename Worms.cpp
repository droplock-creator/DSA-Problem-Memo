// Link to question: https://codeforces.com/problemset/problem/474/B

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    int l,h,mi;
    cin >> n;
    vector<int> pile(n,0);
    for(int i = 0; i < n; i++){
        cin >> pile[i];
        if(i > 0){
            pile[i] += pile[i-1];
        }
    }
    cin >> m;
    vector<int> label(m,0);
    for(int i = 0; i < m; i++){
        cin >> label[i];
    }
    for(int i = 0; i < m; i++){
        l = 0;
        h = n-1;
        while(h != l){
            mi = (l+h)/2;
            if( label[i] <= pile[mi] ){
                h = mi; 
            }
            else{
                l = mi+1;
            }
        }
        cout << l+1 << endl;
    }
}
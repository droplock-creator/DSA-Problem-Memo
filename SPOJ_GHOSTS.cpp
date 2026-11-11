// Link to question: https://www.spoj.com/problems/GHOSTS/

#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>

using namespace std;


int main(){
    
    int k,t;
    cin>>k;
    cin>>t;
    bitset<1001> reach[1001];
    for(int i=1;i<=k;i++){
        reach[i][i] = true;
    }
    while(t--){
        int a,b;
        cin >> a >> b;
        if(reach[b][a]){
            cout << a << " " << b << "\n";
            continue;
        }
        if(reach[a][b]){
            continue;
        }
        for(int i=1;i<=k;i++){
            if(reach[i][a]){
                reach[i] |= reach[b];
            }
        }
    }
    cout << "0 0\n";
}
// Link to question: https://www.spoj.com/problems/EKO/https://www.spoj.com/problems/EKO/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    long long m,l=0,h=1e9,mid;
    cin >> n >> m;
    vector<long long> trees(n,0);
    for( int i = 0; i < n; i++){
        cin >> trees[i];
    }
    while(h != l){
        long long sum = 0;
        mid = (l+h+1)/2;
        for( int i = 0; i < n; i++){
            sum += max(trees[i]-mid,0ll);
        }
        if( sum >= m){
            l = mid;
        }
        else{
            h = mid - 1;
        }
    }
    cout << l << endl;
}
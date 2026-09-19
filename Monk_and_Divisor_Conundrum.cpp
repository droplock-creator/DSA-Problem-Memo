// Link to question: https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}

int main(){
    int n,t,m=0,a;
    cin >> n;
    unordered_map<int,int> A;
    for(int i=0; i<n; i++){
        cin >> a;
        A[a]++;
        m = max(m,a);
    }


    vector<int> F(200001,0);
    for(int i=2; i<F.size(); i++){
        for(int j=i; j<=m; j+=i){
            if(A.find(j) != A.end()){
                F[i] = F[i] + A[j];
            }
        }
    }
    cin >> t;
    while(t--){
        int p,q,ans;
        cin>>p>>q;
        if(p==1 || q==1){
            ans = n;
        }
        else{
            ans = F[p] + F[q];
            long long lcm = (p*1ll*q)/gcd(p,q);
            ans -= (lcm <= m) ? F[lcm]:0;
        }
        cout << ans << endl;

    }
}
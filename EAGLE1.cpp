// Link to question: https://www.spoj.com/problems/EAGLE1/

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

void dfs(vector<vector<pair<int,int>>> &g,int i,int p,vector<long long> &v){
    for(auto child:g[i]){
        if(child.first == p) continue;
        v[child.first] = v[i] + child.second;
        dfs(g,child.first,i,v); 
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<pair<int,int>>> g(n+1);
        vector<long long> v1(n+1,0);
        vector<long long> v2(n+1,0);
        for(int i=0;i<n-1;i++){
            int a,b,c;
            cin >> a >> b >> c;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        dfs(g,1,0,v1);
        long long mD=-1;
        int mN;
        for(int i=1;i<=n;i++){
            if(mD<v1[i]){
                mD=v1[i];
                mN=i;;
            }
            v1[i] = 0;
        }
        mD=-1;
        dfs(g,mN,0,v1);
        for(int i=1;i<=n;i++){
            if(mD<v1[i]){
                mD=v1[i];
                mN=i;;
            }
        }
        dfs(g,mN,0,v2);
        for(int i=1;i<=n;i++){
            cout << max(v1[i],v2[i]) << " ";
        }
        cout << endl;

    }
}
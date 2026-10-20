// Link to question: https://codeforces.com/problemset/problem/580/C

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<vector<int>> &g,int i,int p,int max,int &m,vector<int> &cat){
    bool f = false;
    (cat[i]) ? max++:max=0;
    if(max > m){
        return;
    }
    for(int c:g[i]){
        if(c==p) continue;
        f=true;
        dfs(g,c,i,max,m,cat);
        
    }
    if(!f){
        cat[i] = 2;
    }
}

int main(){
    int n,m,max=0;
    cin >> n >> m;
    vector<int>cat(n+1,0);
    for(int i=1;i<n+1;i++){
        cin >> cat[i];
    }
    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(g,1,0,max,m,cat);
    max=0;
    for(int i=1;i<cat.size();i++){
        if(cat[i]==2){
            max++;
        }
    }
    cout << max;

}
// Link to question: https://www.spoj.com/problems/WATER/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void bfs(vector<vector<int>> &g,vector<vector<bool>> &v,int &ans){
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    for(int i=0;i<g.size();i++){
        for(int j=0;j<g[0].size();j++){
            if(i==0 || j==0 || i==g.size()-1 || j==g[0].size()-1){
                pq.push({g[i][j],{i,j}});
                v[i][j] = true;
            }
        }
    }
    int xc[]={-1,0,1,0};
    int yc[]={0,1,0,-1};
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int i=x.second.first;
        int j=x.second.second;
        for(int k=0;k<4;k++){
            if(i+xc[k]<0 || i+xc[k]>=g.size() || j+yc[k]<0 || j+yc[k]>=g[0].size()) continue;
            if(!v[i+xc[k]][j+yc[k]]){
                int eff_h = max(0,x.first - g[i+xc[k]][j+yc[k]]);
                ans+=eff_h;
                pq.push({g[i+xc[k]][j+yc[k]]+eff_h,{i+xc[k],j+yc[k]}});
                v[i+xc[k]][j+yc[k]] = true;
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> g(n,vector<int>(m));
        vector<vector<bool>> v(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> g[i][j];
            }
        }
        int ans = 0;
        bfs(g,v,ans);
        cout<<ans<<endl;
    }
}
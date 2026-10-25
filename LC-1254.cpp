// Link to question: https://leetcode.com/problems/number-of-closed-islands/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> v(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!v[i][j] && grid[i][j]==0){
                    bool f=true;
                    dfs(grid,v,i,j,f);
                    if(f){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>> &g,vector<vector<bool>> &v,int i,int j,bool &f){
        if(i==0 || i==g.size()-1 || j==0 || j==g[0].size()-1){
            f=false;
        }
        v[i][j] = true;
        int x[]={-1,0,1,0};
        int y[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            if(i+x[k]<0 || i+x[k]>g.size()-1 || j+y[k]<0 || j+y[k]>g[0].size()-1) continue;
            if(!v[i+x[k]][j+y[k]] && g[i+x[k]][j+y[k]]==0){
                dfs(g,v,i+x[k],j+y[k],f);
            }
        }
    }
};
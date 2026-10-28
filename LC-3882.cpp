// Link to question: https://leetcode.com/problems/minimum-xor-path-in-a-grid/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        int res=0;
        int m=grid.size();
        int n = grid[0].size();
        vector<vector<vector<bool>>> v(m,vector<vector<bool>>(n,vector<bool>(1024,false)));
        dfs(grid,0,0,res,ans,v);
        return ans;
    }

    void dfs(vector<vector<int>> &grid,int i,int j, int res,int &ans, vector<vector<vector<bool>>> &v){
        res = res^grid[i][j];
        v[i][j][res] = true;
        if(i == grid.size()-1 && j == grid[0].size()-1){
            ans = min(res,ans);
            return;
        }
        int x[]={0,1};
        int y[]={1,0};

        for(int k=0;k<2;k++){
            if(i+x[k]<0||i+x[k]>=grid.size()||j+y[k]<0||j+y[k]>=grid[0].size()) continue;
            else if( !v[i+x[k]][j+y[k]][res^grid[i+x[k]][j+y[k]]] ){
                dfs(grid,i+x[k],j+y[k],res,ans,v); 
            }
        }
    }
};
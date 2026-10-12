// Link to question: https://leetcode.com/problems/pacific-atlantic-water-flow/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> vP(m,vector<bool>(n,false));
        vector<vector<bool>> vA(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            if(i==0){
                for(int j=0;j<n;j++){
                    dfs(heights,i,j,vP);
                }
            }else{
                dfs(heights,i,0,vP);
            }
        }
        for(int i=0;i<m;i++){
            if(i==m-1){
                for(int j=n-1;j>=0;j--){
                    dfs(heights,i,j,vA);
                }
            }else{
                dfs(heights,i,n-1,vA);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vP[i][j] && vA[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }

    void dfs(const vector<vector<int>> &grid, int i,int j,vector<vector<bool>> &visited){
        visited[i][j] = true;
        int x[] = {-1,0,1,0};
        int y[] = {0,1,0,-1};
        
        for(int k=0;k<4;k++){
            if( (i+x[k])<0 || (i+x[k])>grid.size()-1 || (j+y[k])<0 || (j+y[k])>grid[0].size()-1 ){
                continue;
            }
            else{
                if(grid[i+x[k]][j+y[k]] >= grid[i][j] && !visited[i+x[k]][j+y[k]]){
                    dfs(grid,i+x[k],j+y[k],visited);
                }
            }
        }
    }
};
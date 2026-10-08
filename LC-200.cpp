// Link to question: https://leetcode.com/problems/number-of-islands/description/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int islands=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( !visited[i][j] && grid[i][j] == '1' ){
                    islands++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return islands;
    }
    void dfs( vector<vector<char>> &grid,int i,int j, vector<vector<bool>> &visited ){
        visited[i][j] = true;
        int x[] = {-1,0,1,0};
        int y[] = {0,1,0,-1};
        
        for(int k=0;k<4;k++){
            if( (i+x[k])<0 || (i+x[k])>grid.size()-1 || (j+y[k])<0 || (j+y[k])>grid[0].size()-1 ){
                continue;
            }
            else{
                if(grid[i+x[k]][j+y[k]] == '1' && !visited[i+x[k]][j+y[k]]){
                    dfs(grid,i+x[k],j+y[k],visited);
                }
            }
        }
    }
};
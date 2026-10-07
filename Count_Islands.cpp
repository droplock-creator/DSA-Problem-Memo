// Link to question: https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1?category=

#include<iostream>
#include<vector>

using namespace std;


class Solution {
  public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int islands=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( !visited[i][j] && grid[i][j] == 'L' ){
                    islands++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return islands;
    }
    
    void dfs( vector<vector<char>> &grid,int i,int j, vector<vector<bool>> &visited ){
        visited[i][j] = true;
        int a = (i==0) ? 0:i-1;
        
        for(a; a<=i+1 && a<grid.size(); a++ ){
            int b = (j==0) ? 0:j-1;
            for(b; b<=j+1 && b<grid[0].size(); b++ ){
                if( !visited[a][b] && grid[a][b] == 'L' ){
                    dfs(grid,a,b,visited);
                }
            }
        }
    } 
};

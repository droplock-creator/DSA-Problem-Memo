// Link to question: https://leetcode.com/problems/island-perimeter/description/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p=0;
        bool t=false;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    dfs(grid,i,j,visited,p);
                    t=true;
                    break;
                }
            }
            if(t){
                break;
            }
        }
        return p;
    }

    void dfs(const vector<vector<int>> &grid,int i,int j, vector<vector<bool>> &visited,int &p){
        p+=4;
        visited[i][j] = true;
        int x[] = {-1,0,1,0};
        int y[] = {0,1,0,-1};
        
        for(int k=0;k<4;k++){
            if( (i+x[k])<0 || (i+x[k])>grid.size()-1 || (j+y[k])<0 || (j+y[k])>grid[0].size()-1 ){
                continue;
            }
            else{
                if(grid[i+x[k]][j+y[k]] == 1){
                    p--;
                    if(!visited[i+x[k]][j+y[k]]){
                        dfs(grid,i+x[k],j+y[k],visited,p);
                    }
                }
            }
        }
    }
};
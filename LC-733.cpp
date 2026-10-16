// Link to question: https://leetcode.com/problems/flood-fill/description/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        dfs(image,sr,sc,visited,color,image[sr][sc]);
        image[sr][sc] = color;
        return image;
    }

    void dfs(vector<vector<int>> &grid,int sr,int sc,vector<vector<bool>> &visited,int color,int a){
        visited[sr][sc] = true;
        int x[] ={-1,0,1,0}; 
        int y[] ={0,1,0,-1};

        for(int k=0;k<4;k++){
            if( (sr+x[k])<0 || (sr+x[k])>grid.size()-1 || (sc+y[k])<0 || (sc+y[k])>grid[0].size()-1 ){
                continue;
            }
            else{
                if(grid[sr+x[k]][sc+y[k]] == a && !visited[sr+x[k]][sc+y[k]]){
                    grid[sr+x[k]][sc+y[k]] = color;
                    dfs(grid,sr+x[k],sc+y[k],visited,color,a);
                }
            }
        } 
    }
};
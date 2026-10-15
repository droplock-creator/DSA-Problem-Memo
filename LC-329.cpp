// Link to question: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<vector<int>> maxi(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( !visited[i][j] ){
                    dfs(matrix,i,j,visited,maxi);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,maxi[i][j]);
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>> &matrix,int i,int j, vector<vector<bool>> &visited,vector<vector<int>> &maxi){
        visited[i][j] = true;
        int x[] ={-1,0,1,0}; 
        int y[] ={0,1,0,-1};

        for(int k=0;k<4;k++){
            if( (i+x[k])<0 || (i+x[k])>matrix.size()-1 || (j+y[k])<0 || (j+y[k])>matrix[0].size()-1 ){
                continue;
            }
            else{
                if(matrix[i+x[k]][j+y[k]] > matrix[i][j]){
                    if( visited[i+x[k]][j+y[k]] ){
                        maxi[i][j] = max(maxi[i][j],maxi[i+x[k]][j+y[k]]+1);
                    }
                    else{
                        dfs(matrix,i+x[k],j+y[k],visited,maxi);
                        maxi[i][j] = max(maxi[i][j],maxi[i+x[k]][j+y[k]]+1);
                    }
                }
            }
        } 
        maxi[i][j] = max(maxi[i][j],1);
    }
};
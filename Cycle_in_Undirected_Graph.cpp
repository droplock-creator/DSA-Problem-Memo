// Link to question: https://www.interviewbit.com/problems/cycle-in-undirected-graph/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void dfs(int v,int u,vector<bool>&V,vector<vector<int>> &g,bool &f){
    V[v] = true;
    for(int i=0;i<g[v].size();i++){
        if(f){
            return;
        }
        if( V[g[v][i]] ){ 
            if( g[v][i]!=u){
                f = true;
                return;
            }
        }
        else{
            dfs(g[v][i],v,V,g,f);   
        }
    }
    
}

int solve(int A, vector<vector<int> > &B) {
    vector<bool>v(A+1,false);
    vector<vector<int>> graph(A+1);
    bool flag=false;
    for(int i=0;i<B.size();i++){
        graph[B[i][0]].push_back(B[i][1]);
        graph[B[i][1]].push_back(B[i][0]);
    }
    for(int i=1;i<=A;i++){
        if(v[i] == true){
            continue;
        }
        dfs(i,0,v,graph,flag);
    }
    if(flag){
        return 1;
    }
    else{
        return 0;
    }
    
}

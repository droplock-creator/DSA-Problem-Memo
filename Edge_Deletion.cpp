// Link to question: https://www.interviewbit.com/problems/delete-edge/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<vector<int>> &g,int v,int p, vector<int> &A, vector<int> &sum){
    for(int c:g[v]){
        if(c==p) continue;
        dfs(g,c,v,A,sum);
        sum[v-1] += sum[c-1];
    }
    sum[v-1] += A[v-1];
}

int deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    vector<vector<int>> g(A.size()+1);
    vector<int> sum(A.size(),0);
    long long ans = 0;
    for(int i=0;i<B.size();i++){
        g[B[i][0]].push_back(B[i][1]);
        g[B[i][1]].push_back(B[i][0]);
    }
    dfs(g,1,0,A,sum);
    for(int i=2;i<=A.size();i++){
        int p1 = sum[i-1];
        int p2 = sum[0] - p1;
        ans = max(ans,p1*1ll*p2);
    }
    return ans % 1000000007;
}

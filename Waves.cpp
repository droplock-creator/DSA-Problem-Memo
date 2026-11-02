// Link to question: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/waves-b18625d7/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &g,int a,int b,vector<vector<bool>> &v){
    queue<pair<int,int>> q;
    q.push({a,b});
    v[a][b] = true;
    while(!q.empty()){
        a = q.front().first;
        b = q.front().second;
        q.pop();
        int x[]={-1,-1,0,1,1,1,0,-1};
        int y[]={0,1,1,1,0,-1,-1,-1};
        for(int k=0;k<8;k++){
            if(a+x[k] < 0 || a+x[k] >= g.size() || b+y[k]<0 || b+y[k]>=g[0].size()){
                continue;
            }
            else if(!v[a+x[k]][b+y[k]]){
                g[a+x[k]][b+y[k]] = g[a][b] + 1;
                q.push({a+x[k],b+y[k]});
                v[a+x[k]][b+y[k]] = true;
            }
        }
    }
}

int main() {
    int r,c,c1,c2;
    cin >> r >> c >> c1 >> c2;
    vector<vector<int>> g(r,vector<int>(c));
    vector<vector<bool>> v(r,vector<bool>(c,false));
    bfs(g,c1,c2,v);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

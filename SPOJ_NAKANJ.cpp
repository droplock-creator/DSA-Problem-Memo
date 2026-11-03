// Link to question: https://www.spoj.com/problems/NAKANJ/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

void bfs(vector<vector<int>> &g, int a,int b, vector<vector<bool>> &v){
    queue<pair<int,int>> q;
    q.push({a,b});
    v[a][b] = true;
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        int x[]={2,2,1,-1,-2,-2,-1,1};
        int y[]={-1,1,2,2,1,-1,-2,-2};
        for(int k=0;k<8;k++){
            if(i+x[k]<0||i+x[k]>=8||j+y[k]<0||j+y[k]>=8) continue;
            else{
                if(!v[i+x[k]][j+y[k]]){
                    g[i+x[k]][j+y[k]] += g[i][j] + 1;
                    q.push({i+x[k],j+y[k]});
                    v[i+x[k]][j+y[k]] = true;
                }
            }
        }
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        int s1,s2,d1,d2;
        s2 = a[0]-'a';
        s1 = a[1] - '1';
        d2 = b[0] - 'a';
        d1 = b[1] - '1';
        vector<vector<int>> g(8,vector<int>(8,0));
        vector<vector<bool>> v(8,vector<bool>(8,false));
        bfs(g,s1,s2,v);
        cout << g[d1][d2] << endl;
    }
}
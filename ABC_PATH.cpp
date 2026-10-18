// Link to question: https://www.spoj.com/problems/ABCPATH/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void dfs(vector<vector<char>> &g,int i,int j,vector<vector<int>> &m,int &p,int &path){
    if(m[i][j] != 0){
        path = max(path,p+m[i][j]);
        return;
    }
    path = max(path,p);
    int x[]={-1,-1,0,1,1,1,0,-1};
    int y[]={0,1,1,1,0,-1,-1,-1};
    for(int k=0;k<8;k++){
        if(i+x[k]<0 || i+x[k]>=g.size() || j+y[k]<0 || j+y[k]>=g[0].size() ){
            continue;
        }
        if(g[i+x[k]][j+y[k]] - g[i][j] == 1){
            p++;
            dfs(g,i+x[k],j+y[k],m,p,path);
            p--;
            m[i][j] = max(m[i][j],m[i+x[k]][j+y[k]]+1); 
        }
    }
}

int main(){
    int h,w;
    int a=0;
    while(cin >> h >> w && (h != 0 || w != 0)){
        a++;
        int path = 0;
        vector<vector<int>> mem(h,vector<int>(w,0));
        vector<vector<char>> g(h,vector<char>(w));
        for(int i=0;i<h;i++){
            string s;
            cin >> s;
            for(int j=0;j<w;j++){
                g[i][j] = s[j];
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(g[i][j] == 'A'){
                    int p=1;
                    dfs(g,i,j,mem,p,path);
                }
            }
        }
        cout << "Case " << a << ": " << path << endl;
    }
}
// Link to question: https://www.spoj.com/problems/KOZE/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(int i,int j, vector<vector<char>> &g, vector<vector<bool>> &v,int &s,int &w,int &s1,int &w1,bool &f){
    v[i][j]  = true;
    if(i == 0 || i == g.size()-1 || j==0 || j == g[0].size()-1){
        f=true;
    }
    if(g[i][j]=='k'){
        s++;
    }else if(g[i][j]=='v'){
        w++;
    }
    int x[]={-1,0,1,0};
    int y[]={0,1,0,-1};

    for(int k=0;k<4;k++){
        if(i+x[k]<0 || i+x[k]>=g.size() || j+y[k]<0 || j+y[k]>=g[0].size()) continue;
        if(!v[i+x[k]][j+y[k]] && g[i+x[k]][j+y[k]]!='#'){
            dfs(i+x[k],j+y[k],g,v,s,w,s1,w1,f);
        }
    }
}

int main(){
    int n,m;
    int s=0,w=0;
    cin >> n >> m;
    vector<vector<char>> g(n,vector<char>(m));
    vector<vector<bool>> v(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> g[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!v[i][j] && g[i][j]!='#'){
                int s1=0,w1=0;
                bool f=false;
                dfs(i,j,g,v,s1,w1,s,w,f);
                if(f){
                    w+=w1;
                    s+=s1;
                }
                else if(w1>=s1){
                    w+=w1;
                }else{
                    s+=s1;
                }
            }
        }
    }
    cout << s << " " << w;

}
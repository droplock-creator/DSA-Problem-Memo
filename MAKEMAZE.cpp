// Link to question: https://www.spoj.com/problems/MAKEMAZE/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(vector<vector<char>> &g,vector<vector<bool>> &v,int i,int j,bool &f){
    if(f) return;
    v[i][j] = true;
    int x[]={-1,0,1,0};
    int y[]={0,1,0,-1};
    for(int k=0;k<4;k++){
        if(i+x[k]<0 || i+x[k]>=g.size() || j+y[k]<0 || j+y[k]>=g[0].size()) continue;
        if(!v[i+x[k]][j+y[k]] && g[i+x[k]][j+y[k]] == '.'){
            if((i+x[k])*(j+y[k])==0 || i+x[k] == g.size()-1 || j+y[k] == g[0].size()-1){
                f=true;
                break;
            }
            dfs(g,v,i+x[k],j+y[k],f);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n,ct=0;
        cin >> m >> n;
        vector<int> cord;
        vector<vector<char>> g(m,vector<char>(n));
        vector<vector<bool>> v(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin >> g[i][j];
                if(i*j==0 || i== m-1 || j==n-1){
                    if(g[i][j] == '.'){
                        ct++;
                        cord.push_back(i);
                        cord.push_back(j);
                    } 
                }
            }
        }
        if(ct!=2){
            cout << "invalid" << endl;
        }
        else{
            bool f =false;
            dfs(g,v,cord[0],cord[1],f);
            if(f){
                cout << "valid" << endl;
            }
            else{
                cout << "invalid" << endl;
            }
        }

    }
}
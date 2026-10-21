// Link to question: https://www.spoj.com/problems/ADASEA/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(int i,int j, vector<vector<bool>> &v,vector<vector<char>> &g,int &s){
    v[i][j] = true;
    s++;
    int x[]={-1,0,1,0};
    int y[]={0,1,0,-1};

    for(int k=0;k<4;k++){
        if(i+x[k]>=g.size() || i+x[k]<0 || j+y[k]<0 || j+y[k]>=g[0].size()) continue;
        else if(!v[i+x[k]][j+y[k]] && g[i+x[k]][j+y[k]] == '#'){
            dfs(i+x[k],j+y[k],v,g,s);
        }
    }

}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,s=0;
        cin >> n >> m;
        long long ans = 0;
        vector<vector<char>> g(n,vector<char>(m));
        vector<vector<bool>> v(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> g[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!v[i][j] && g[i][j] == '#'){
                    dfs(i,j,v,g,s);
                    ans += s*1ll*s;
                    s=0;
                }
            }
        }
        long long total = 1LL * n * m;

        if (ans == 0) {
            cout << 0 << '\n';
            continue;
        }

        long long a = gcd(ans, total);
        cout << ans / a;

        if (total / a != 1) {
            cout << " / " << total / a;
        }
        cout << '\n';   
    }
}
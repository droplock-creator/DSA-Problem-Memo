// Link to question: https://spoj.com/problems/AKBAR/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<vector<int>> &g,vector<int> &level,int i,int m,bool &f,vector<int> &guard){
    if(guard[i]!=0){
        f=false;
        return;
    }
    queue<int> q;
    q.push(i);
    level[i] = 0;
    guard[i] = i;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(auto c:g[a]){
            if(level[a]+1>m) return;
            if(guard[c]!=0 && guard[c]!=i){
                f=false;
                return;
            }
            else{
                if(guard[c]==0){
                    level[c] = level[a]+1;
                    guard[c] = i;
                    q.push(c);
                }
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,r,m;
        bool f = true;
        cin >> n >> r >> m;
        vector<vector<int>> g(n+1);
        vector<int> level(n+1,0);
        vector<int> guard(n+1,0);
        for(int i=0;i<r;i++){
            int a,b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i=0;i<m;i++){
            int a,b;
            cin >> a >> b;
            if(f){
                bfs(g,level,a,b,f,guard);
            }
        }
        if(f){
            for(int i=1;i<n+1;i++){
                if(guard[i]==0){
                    cout << "No" << endl;
                    f=false;
                    break;
                }
            }
            if(f){
                cout << "Yes" << endl; 
            }
        }
        else{
            cout << "No" << endl;
        }

    }
}
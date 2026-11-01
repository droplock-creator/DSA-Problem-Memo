// Link to question: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/cloudy-days-82a872ec/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

void bfs(const vector<vector<int>> &g,int i,int &ct,const int &k,vector<bool> &v,vector<int> &level){
  queue<int> q;
  q.push(i);
  v[i] = true;
  ct++;
  while(!q.empty()){
    int a = q.front();
    q.pop();
    for(auto c:g[a]){
        if(!v[c]){
            if(level[a]+1>k){
                return;
            }
            else{
                q.push(c);
                v[c]=true;
                level[c] = level[a]+1;
                ct++;
            }
        }
    }
  }
}


int main() {
    int n,m,k,c;
    cin >> n >> m >> k >> c;
    vector<vector<int>> g(n+1);
    vector<bool> v(n+1,false);
    vector<int> level(n+1,0);
    for(int i=0;i<m;i++){
      int a,b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    int ct=0;
    bfs(g,c,ct,k,v,level);
    cout << ct << endl;

}


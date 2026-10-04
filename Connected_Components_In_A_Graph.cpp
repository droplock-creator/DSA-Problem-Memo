// Link to question: https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 1e5+10;
bool visited[N];
vector<int> graph[N];

void DFS(int v){
    visited[v]=true;
    for(int i=0;i<graph[v].size();i++){
        if(visited[graph[v][i]] == true){
            continue;
        }
        DFS(graph[v][i]);
    }
    return;
}

int main(){
    int n,e,ct=0;
    cin >> n >> e;
    for(int i=0 ; i<e; i++){
        int v1,v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i=1;i<=n;i++){
        if(visited[i] == true){
            continue;
        }
        DFS(i);
        ct++;
    }
    cout << ct;
}
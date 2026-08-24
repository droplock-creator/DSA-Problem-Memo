// Link to question: https://www.hackerearth.com/problem/algorithm/covid-rush/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> arrival(n,0);
    vector<int> treatment(n,0);
    for(int i = 0; i < n; i++){
        cin >> arrival[i];
    }
    for(int i = 0; i < n; i++){
        cin >> treatment[i];
    }
    vector<int> count(m,0);

    set<int> avail;
    for(int i=0; i < m; i++){
        avail.insert(i);
    }

    set<pair<int,int>> center;

    for(int i = 0; i < n; i++){
        while(!center.empty() && center.begin()->first <= arrival[i]){
            auto v = center.begin();
            avail.insert(v->second);
            center.erase(v);
        }
        if(avail.empty()){
            continue;
        }
        auto it = avail.lower_bound(i % m);
        if( it!= avail.end() ){
            center.insert({arrival[i]+treatment[i],*it});
            count[*it]++;
            avail.erase(it);
        }
        else{
            center.insert({arrival[i]+treatment[i],*(avail.begin())});
            count[*(avail.begin())]++;
            avail.erase(avail.begin());
        }
    }
    for(auto i:count){
        cout << i << " ";
    }
}
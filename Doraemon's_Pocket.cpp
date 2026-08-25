// Link to question: https://www.hackerearth.com/problem/algorithm/doraemon-andd-his-pocket-of-wonder/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n;
        vector<int> First(n,0);
        for(int i = 0; i < n; i++){
            cin >> First[i];
        }
        sort(First.begin(), First.end());
        cin >> m;
        vector<int> Second(m,0);
        for(int i = 0; i < m; i++){
            cin >> Second[i];
        }
        unordered_map<int,int> key;
        for(int i = 0; i < n; i++){
            key[First[i]]++;
        }
        for(int i = 0; i < m; i++){
            if(key.find(Second[i]) != key.end()){
                for(int j = 0; j < key[Second[i]]; j++){
                    cout << Second[i] << " ";
                }
                key.erase(Second[i]);
            }
        }
        for(int i = 0; i < n; i++){
            if(key.find(First[i]) != key.end()){
                for(int j = 0; j < key[First[i]]; j++){
                    cout << First[i] << " ";
                }
                key.erase(First[i]);
            }
        }
        cout << endl;
    }
}
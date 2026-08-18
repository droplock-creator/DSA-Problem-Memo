// Link to question: https://www.hackerearth.com/problem/algorithm/too-lazy-to-name-the-question-ii/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<string>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> num(n,{0,0});
    unordered_set<string> points;
    for(int i = 0; i < n; i++){
        cin >> num[i].first >> num[i].second;
        points.insert(to_string(num[i].first)+"-"+to_string(num[i].second));
    }
    long long areaMin = 1e12;
    long long areaMax = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(num[i].first != num[j].first && num[i].second != num[j].second){
                if(points.find(to_string(num[i].first)+"-"+to_string(num[j].second)) != points.end() && points.find(to_string(num[j].first)+"-"+to_string(num[i].second)) != points.end()){
                    areaMax = max( areaMax,(1ll * abs(num[i].first - num[j].first) * abs(num[i].second - num[j].second)) );
                    areaMin = min( areaMin,(1ll * abs(num[i].first - num[j].first) * abs(num[i].second - num[j].second)) );
                }
            }    
        }
    }
    if(areaMax == 0){
        cout << -1 << endl;
    }else{
        cout<< areaMax - areaMin <<  endl;
    }
    

}
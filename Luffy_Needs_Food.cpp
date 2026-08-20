// Link to question: https://www.hackerearth.com/problem/algorithm/luffy-needs-food/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

bool comparator(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first > b.first){
        return true;
    }
    return false;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,count=0;
        long long f;
        cin >> n;
        cin >> k >> f;
        vector<pair<int,int>> Grand(n,{0,0});
        for(int i=0; i < n; i++){
            cin >> Grand[i].first >> Grand[i].second;
        }
        sort(Grand.begin(),Grand.end(),comparator);
        Grand.push_back({0,0});
        multiset<int> s;
        for(int i=0; i < n+1; i++){
            if(k-Grand[i].first > f){
                if(s.empty()){
                    count = -1;
                    break;
                }
                else{
                    while(k-Grand[i].first > f){
                        if(s.empty()){
                            count = -1;
                            break;
                        }
                        f += *(--s.end());
                        s.erase(--s.end());
                        count++;
                    }
                }
                if(count == -1){
                    break;
                }
            }
            f = f - (k-Grand[i].first);
            s.insert(Grand[i].second);
            k = Grand[i].first;
        }  
        cout << count << endl;      
        
    }
}
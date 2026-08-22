// Link to question: https://www.hackerearth.com/problem/algorithm/last-wish/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comparator(const pair<long,long> &a, const pair<long,long> &b){
    if((a.first+a.second) == (b.first + b.second)){
        return a.first < b.first;
    }
    return (a.first+a.second) < (b.first + b.second);
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<long,long>> num(n,{0,0});
        vector<pair<long,long>> num_s(n,{0,0});
        for(int i = 0; i < n; i++){
            cin >> num[i].first >> num[i].second;
            num_s[i].first = num[i].first;
            num_s[i].second = num[i].second;
        }
        sort(num_s.begin(),num_s.end(),comparator);
        for(int i=0; i < n; i++){
            int low = 0, high = n-1;
            while(high != low){
                int mid = (low+high)/2;
                if(comparator(num_s[mid],num[i])){
                    low = mid+1;
                }
                else{
                    high = mid;
                }
            }
            cout << high << " ";
        }
        cout << endl;
    }
}
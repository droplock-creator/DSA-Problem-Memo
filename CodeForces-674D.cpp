// Link to question: https://codeforces.com/contest/1426/problem/D

#include<iostream>
#include<vector>    
#include<unordered_set>    

using namespace std;

int main(){
    int n,count=0;
    cin >> n;
    vector<int>Num(n,0);
    for (int i = 0; i < n; i++){
        cin >> Num[i];
    }
    vector<long long>Psum(n+5,0);
    unordered_set<long long> re;
    re.insert(0);
    Psum[0] = Num[0];
    for (int i = 1; i < n; i++){
        Psum[i] = Psum[i-1]+Num[i];
    }

    for(int i=0; i < n; i++){
        if(re.find(Psum[i]) != re.end()){
            count++;
            re.clear();
            re.insert(Psum[i]);
            if(i != 0){
                re.insert(Psum[i-1]);
            }
        }
        else{
            re.insert(Psum[i]);
        }
    }
    cout << count;
}    
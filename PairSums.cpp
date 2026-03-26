// Link to question: https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/pair-sums/?fbclid=IwAR2XcdRMJnGwG3ojY4diVU80L41VtxP85xk2VWMZ_lUYz58kKYk2TtZN3rc

#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
using namespace std;
int main(){
    int n,k,num;
    cin >> n >> k;
    unordered_set <int> Ct;
    for (int i = 0; i < n; i++){
        cin >> num;
        if(Ct.find(k-num) != Ct.end()){
            cout << "YES" <<endl;
            return 0;
        }
        Ct.insert(num);
    }
    cout << "NO" <<endl;
}
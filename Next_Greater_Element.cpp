// Link to question: https://www.hackerrank.com/contests/second/challenges/next-greater-element/submissions/code/1407483108


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {

    int n;
    cin >> n;
    vector<int> Num(n,0);
    for (int i = 0; i < n; i++){
        cin >> Num[i];
    }
    stack<int>St;
    vector<int> Res(n,-1);
    for (int i = 0; i < n; i++){
        while(!St.empty() && Num[St.top()] < Num[i]){
            Res[St.top()] = Num[i];
            St.pop();
        }
        St.push(i);
    }
    for (int i = 0; i < n; i++){
        cout << Num[i] << " " << Res[i] << endl;
    }
    return 0;
}

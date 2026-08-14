// Link to question: https://www.codechef.com/practice/course/binary-search/INTBINS01/problems/MINEAT

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(vector<int> &A, int m, int H){
    for(int i = 0; i < A.size(); i++){
        if(A[i] <= m){
            H--;
        }
        else{
            H -= (A[i] + m -1)/m;
        }
        if(H < 0){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,h;
        int low = 1,high = 0;
        cin >> n >> h;
        vector<int> Pile(n,0);
        for(int i = 0; i < n; i++){
            cin >> Pile[i];
            high = max(high,Pile[i]);
        }
        while(high != low){
            int mid = (high+low)/2;
            if(isValid(Pile,mid,h)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        cout << low << endl;

    }
}
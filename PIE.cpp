// Link to question: https://www.spoj.com/problems/PIE/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

bool isValid(vector<double> &arr,double m, int k){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] >= m){
            k -= int(arr[i]/m);
        }
        if(k == 0){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,f;
        cin >> n >> f;
        vector<double> pie(n,0);
        for(int i = 0; i < n; i++){
            cin >> pie[i];
            pie[i] = pie[i]*pie[i]*acos(-1.0);
        }
        sort(pie.begin(),pie.end());
        double low = pie[0]/(f+1), high = pie[n-1];
        while(high - low >= 1e-4){
            double mid = (high+low)/2;
            if(isValid(pie,mid,f+1)){
                low = mid;
            }
            else{
                high = mid;
            }
        } 
        cout << fixed << setprecision(4) << low << endl;

    }
}
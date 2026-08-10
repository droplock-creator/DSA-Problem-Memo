// This is the application of Binary search to find Nth root of a number

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double eps = 1e-4;

int main(){
    int n;
    double num;
    cout << "Enter value of N: ";
    cin >> n;
    cout<< "Enter the number: ";
    cin >> num;
    double lo = 1, hi = num, mid;
    while( hi-lo > eps ){
        mid = (lo+hi)/2;
        if( pow(mid,n) > num ){
            hi = mid;
        }
        else{
            lo = mid;
        }
    } 
    cout << "The square root of "<< num << " is: " << fixed << setprecision(3) << lo << endl;
}
/* Roy likes Symmetric Logos.

How to check whether a logo is symmetric?
Align the center of logo with the origin of Cartesian plane. Now if the colored pixels of the logo are symmetric about both X-axis and Y-axis, then the logo is symmetric.

You are given a binary matrix of size N x N which represents the pixels of a logo.
1 indicates that the pixel is colored and 0 indicates no color.*/

#include <iostream>
#include<vector>
#include <string>
#include <algorithm>
using namespace std;
bool symmetry(vector<vector<int>> &a,int r){
  for(int i=0;i<r;i++){
    for(int j=0;j<(r/2);j++){
      if(a[i][j]!=a[i][r-1-j]){
        return false;
      }
    }
  }
  for(int i=0;i<(r/2);i++){
    for(int j=0;j<r;j++){
      if(a[i][j]!=a[r-1-i][j]){
        return false;
      }
    }
  }
  return true;
}
int main() {
    int t;
    cin>>t;
    while(t--){
      string ans;
      int N;
      cin>>N;
      vector<vector<int>> arr1(N,vector<int>(N));
      for(int i=0;i<N;i++){
        string s;
        cin>>s;
        for(int j=0;j<N;j++){
          arr1[i][j]=s[j]-'0';
        }
      }
      if(symmetry(arr1,N)){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }
}

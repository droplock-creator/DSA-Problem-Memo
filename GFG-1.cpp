/* Given a matrix A of dimensions NxM. Check whether the sum of the ith row is equal to the sum of the ith column.
Note: Check only up to valid row and column numbers i.e if the dimensions are 3x5, check only for the first 3 rows and columns, i.e. min(N, M).*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    int sumOfRowCol(int N, int M, vector<vector<int>> A) {
        int k=min(N,M);
        vector<int>sumR;
        for(int i=0;i<k;i++){
            int s=0;
            for(int j=0;j<M;j++){
                s+=A[i][j];
            }
            sumR.push_back(s);
        }
        for(int i=0;i<k;i++){
            int s=0;
            for(int j=0;j<N;j++){
                s+=A[j][i];
            }
            if(s==sumR[i]){
                return i+1;
            }
        }
        return 0;
        
    }
};
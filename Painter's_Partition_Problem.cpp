// Link to question: https://www.interviewbit.com/problems/painters-partition-problem/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isValid(vector<int> &C,long long m,int A){
    long long sum = 0;
    for(int i = 0; i < C.size(); i++){
        if(sum + C[i] > m){
            A--;
            sum = C[i];
        }
        else{
            sum = sum + C[i];
        }
    }
    if(A < 0){
        return false;
    }
    return true;
}

long long Solution(int A, int B, vector<int> &C) {
    if(A >= C.size()){
        return C[C.size()-1]*B;
    }
    else{
        long long low=0,high=0;
        for(int i = 0; i < C.size(); i++){
            low = max(long long (C[i]),low);
            high += C[i];
        }
        low = low * B;
        high = high * B;
        while(high != low){
            long long mid = (high+low)/2;
            if(isValid(C,mid,A)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
}


// Link to question: https://leetcode.com/problems/reverse-pairs/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ct = 0;
        mergeSort(nums,ct,0,n-1);
        return ct;
    }

    void mergeSort(vector<int> &nums,int &ct,int low,int high){
        if(low==high){
            return;
        }
        int mid = (low + high)/2;
        mergeSort(nums,ct,low,mid);
        mergeSort(nums,ct,mid+1,high);
        merge(nums,low,mid,high,ct); 
    }
    void merge(vector<int> &nums,int l,int m,int h,int &ct){
        vector<long long> low;
        vector<long long> high;
        for(int i=l;i<=m;i++){
            low.push_back(nums[i]);
        }
        for(int i=m+1;i<=h;i++){
            high.push_back(nums[i]);
        }
        int a = 0;
        int b = 0;
        for(int i=l;i<=h;i++){
            if(low[a] > 2*high[b]){
                ct += low.size()-a;
                b++;
                if(b==high.size()){
                    break;
                }
            }else{
                a++;
                if(a==low.size()){
                    break;
                }
            }
        }
        low.push_back(LLONG_MAX);
        high.push_back(LLONG_MAX);
        a=0;
        b=0;
        for(int i=l;i<=h;i++){
            if(low[a] <= high[b]){
                nums[i]=low[a];
                a++;
            }else{
                nums[i] = high[b];
                b++;
            }
        }

    }
};
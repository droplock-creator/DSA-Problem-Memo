// CodeChef Jewel and Stones


#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    vector<int>hash(100,0);
	    int ct=0;
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    for(int i=0;i<s1.size();i++){
	        hash[int(s1[i])-int('A')]++;
	    }
	    for(int i=0;i<s2.size();i++){
	        if(hash[int(s2[i])-int('A')]>0){
	            ct++;
	        }
	    }
	    cout<<ct<<endl;
	}

}


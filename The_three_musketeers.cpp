// Link to question: https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

long long comb(int a,int b){
    long long ans = 1;
    int c = a-b;
    for(int i=a;i>c;i--){
        ans = ans*i;
    }
    if(b==3){
        return ans/6;
    }else{
        return ans/b;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long ct = 0;
        cin >> n;
        if(n<3){
            cout << 0 << "\n";
            continue;
        }
        vector<int>  name(32,0);
        for(int i=0;i<n;i++){
            string a;
            int b=0;
            cin >> a;
            for(int j=0;j<a.length();j++){
                switch (a[j]){
                    case 'a':
                        b = b|1;
                        break;
                    case 'e':
                        b = b|2;
                        break;
                    case 'i':
                        b=b|4;
                        break;
                    case 'o':
                        b=b|8;
                        break;
                    case 'u':
                        b=b|16;
                        break;
                }
            }
            name[b]++;
        }
        for(int i=1;i<32;i++){
            for(int j=i;j<32;j++){
                for(int k=j;k<32;k++){
                    if(i==j && j==k){
                        ct += comb(name[i],3);
                    }
                    else if(i==j && (j&k) != 0){
                        ct += comb(name[i],2)*name[k];
                    }
                    else if(j==k && (i&j)!=0){
                        ct+= comb(name[j],2)*name[i];
                    }
                    else if((i&j&k) != 0){
                        ct+= 1ll*name[i]*name[j]*name[k];
                    }
                }
            }
        }
        cout << ct << "\n";
        
    }
}
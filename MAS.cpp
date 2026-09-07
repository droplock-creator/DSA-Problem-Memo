// Link to question: https://www.spoj.com/problems/MAS/

#include<iostream>
#include<vector>

using namespace std;

long long binMultiply(long long a, long long b, long long m){
    long long ans = 0;
    while(b>0){
        if(b&1){
            ans = (ans+a) % m;
        }
        a = (a+a) % m;
        b >>= 1;
    }
    return ans;
}

long long F(int n,long long &ss, long long &s, long long m){
    long long x;
    x = ( (n*ss) % m - binMultiply(s,s,m) + m ) % m;
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long m = 2760727302517;
    int t,c=0;
    cin >> t;
    while(t--){
        int n,q;
        long long s=0,ss=0;
        cin >> n >> q;
        vector<long long> nums(n,0);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
            s += nums[i];
            ss = ( ss + (nums[i]*nums[i]) ) % m;
        }
        cout << "Case " << ++c << ":" << endl;
        while(q--){
            int a;
            cin >> a;
            if(a == 1){
                long long x,v;
                cin >> x >> v;
                x--;
                s = s - nums[x] + v;
                ss = (ss - binMultiply(nums[x],nums[x],m) + m ) % m;
                ss = (ss + binMultiply(v,v,m) ) % m;
                nums[x] = v;

            }
            else if(a == 2){
                long long x,v;
                cin >> x >> v;
                x--;
                s = s + v;
                ss = (ss - binMultiply(nums[x],nums[x],m) + m ) % m;
                ss = (ss + binMultiply(nums[x]+v,nums[x]+v,m) ) % m;
                nums[x] += v;
            }
            else{
                cout << F(n,ss,s,m) << endl;
            }
        }
    }
}



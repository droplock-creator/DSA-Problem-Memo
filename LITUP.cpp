// Link to question: https://www.codechef.com/problems/LITUP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,k,m=201;
	    cin >> n >> k;
	    vector<int>lit(n+1,0);
	    for(int i = 1; i <= n; i++){
	        cin >> lit[i];
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=i+1;j<=n;j++){
	            if(i<=k+1 && j>=n-k && j-i<=2*k+1){
	                m = min(m,lit[i]+lit[j]);
	            }
	        }
	    }
	    if(m == 201){
	        cout<<-1<<endl;
	    }else{
	        cout<<m<<endl;
	    }
	    
	}

}

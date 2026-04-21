// Link to question: https://www.hackerearth.com/problem/algorithm/too-lazy-to-name-the-question/


#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
	int a,b,c,step,i=2;
	cin >> a >> b >> c;
	vector<int> Num;
	while (Num.size() < c){
		if (i % a == 0 || i % b == 0){
			Num.push_back(i);
		}
		i++;
	}
	if(Num[c-1] % a == 0 && Num[c-1] % b == 0 ) {step = (a/gcd(a,b))*b;}
	else if(Num[c-1] % a == 0 ) {step = a;} 
	else if(Num[c-1] % b == 0 ) {step = b;} 
 
	i = Num[c-1]; 
	while (i >= 0){
		cout << i << " ";
		i = i - step;
	}
}
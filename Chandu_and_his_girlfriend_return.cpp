// Link to question: https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/chandu-and-his-girlfriend-returns/


#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b){
	vector<int> R;
	int i = 0;
	int j = 0;
	while (i < a.size() && j < b.size()){
		if (a[i] > b[j]){
			R.push_back(a[i]);
			i++;
		}else{
			R.push_back(b[j]);
			j++;
		}
	}
	while (i < a.size()){
		R.push_back(a[i]);
		i++;
	}
	while(j < b.size()){
		R.push_back(b[j]);
		j++;
	}
	return R;
}

int main() {
	int t;
	cin >> t;
	while (t--){
		int n,m;
		cin >> n >> m;
		vector<int> A(n);
		vector<int> B(m);
		for (int i = 0; i < n; i++){
			cin >> A[i];
		}
		for (int i = 0; i < m; i++){
			cin >> B[i];
		}
		auto Res = merge(A,B);
		for (auto v:Res){
			cout << v << " ";
		}
		cout << "\n";
	}
}
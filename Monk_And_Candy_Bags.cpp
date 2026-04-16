// Link to question: https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-the-magical-candy-bags/?fbclid=IwAR2kDiVkEaxu9dkCTCUhzXLuIccNn0Gz3dSfkaSUjlDE6Nb9UHMzt8HNDo4

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,k;
        long long c;
        cin >> n >> k;
        multiset<long long> Candy;
        for (int i = 0; i < n; i++){
            cin >> c;
            Candy.insert(c);
        }
        c = 0;
        for (int i = 0; i < k; i++){
            auto it = --Candy.end();
            c = c + *it;
            Candy.insert(*(it)/2);
            Candy.erase(it);
        }
        cout << c << endl;
    }
}

/* Question -: 

There are N <= 5000 workers. 
Each worker is available during some days of this month (which has 30 days). 
For each worker, you are given a set of numbers, each from interval [1,30], representing his/her availability. 
You need to assign an important project to two workers but they will be able to work on the project only when they are both available. 
Find two workers that are best for the job — maximize the number of days when both these workers are available. */

/* Input -:
    First line contains no.of workers say, n.
    Now the next n*2 lines contain no.of days the worker works and next line contains the days on which he works.

    EXAMPLE -:
        5
        4
        1 4 7 9 
        6
        2 9 1 7 25 29
        7
        1 23 4 7 9 11 29
        10
        2 28 8 7 9 10 30 21 18 19
        4
        1 11 29 7
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n; // No.of Workers
    cin >> n;
    vector<int> days(n,0);
    for(int i = 0; i < n; i++){
        int d, mask=0;
        cin >> d;
        for(int j = 0; j < d; j++){
            int a;
            cin >> a;
            mask = mask | (1<<(a-1));
        }
        days[i] = mask;
    }

    int w1 = -1,w2 = -1;
    int max_days = 0; 

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int d =  __builtin_popcount(days[i] & days[j]);
            if( d > max_days ){
                max_days = d;
                w1 = i;
                w2 = j;
            }
        }
    } 

    cout<< w1 << " and " << w2;
}
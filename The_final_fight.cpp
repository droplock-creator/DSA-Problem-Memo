/*

Fatal Eagle has had it enough with Arjit aka Mr. XYZ who's been trying to destroy the city from the first go.
He cannot tolerate all this nuisance anymore. He's... tired of it. He decides to get rid of Arjit and his allies in a war.
He knows that Arjit has N people fighting for him, so he brings his own N people in the war to face him.
(So, there will be 2 * N people fighting in this war!)

He knows for him to win the war against his enemy, members of his army should be present before the members of Arjit 
come up in the battlefield - that is to say, whenever a member of Arijt's army comes in the battlefield, 
there should already be a member of his own army there to handle him.
(In short, the number of his army members should never be less than the number of Arjit's army members in the field!)

If he figures out the number of ways such such sequences can be formed, the good will be able to conquer evil yet again. 
Help Fatal Eagle in figuring it out to defeat Arjit - once and for all.

Input format:
There is only one integer in the only line of the input, denoting the value of N.

Output format:
Print the number of valid sequences. Since the output might be very big, print it modulo 109+9.

Constraints:
1 <= N <= 105

SAMPLE INPUT 
3
SAMPLE OUTPUT 
5

HINT: Lookup 'CATALAN NUMBERS'

*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long M = 1000000009;

long long binExp(long long a, long long b, long long m){
    long long ans = 1;
    while(b>0){
        if(b&1){
            ans = (ans*a)%m;
        }
        b >>=1;
        a = (a*a)%m;
    }
    return ans;
}

int main(){
    int N;
    cin >> N;
    vector<long long> Facto(200005);
    Facto[0] = 1;
    for(int i=1; i < Facto.size(); i++){
        Facto[i] = (Facto[i-1] * (i%M))%M;
    }
    long long ans = ( binExp(N+1,M-2,M) * ((Facto[2*N]*binExp(((Facto[N]*Facto[N])%M),M-2,M)) % M) ) % M;
    cout << ans;
}
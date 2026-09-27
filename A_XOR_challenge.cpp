// Link to question: https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/

#include<iostream>

using namespace std;


int main(){
    int c,c2,ct=0;
    long long a=0,b=0,d=1;
    cin >> c;
    c2 = c;
    while(c2>0){
        ct++;
        c2>>=1;
    }
    for(int i=ct-1;i>0;i--){
        d = d*2;
    }
    for(int i = ct-1; i>=0; i--){
        if(c&d){
            if((a+d)*b >= (b+d)*a){
                a = a|d;
            }else{
                b = b|d;
            }
        }else{
            a = a|d;
            b = b|d;
        }
        d>>=1;
    }
    cout << a*b;
}
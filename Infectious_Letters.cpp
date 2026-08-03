// Link to question: https://codeforces.com/gym/102892/problem/3
// NOTE: You can solve it using a simple iteration over the string aswell. A recursive solution is not necessary and just makes things more complex.

#include<iostream>
#include<vector>
using namespace std;

void generate(const string &s,int &m){
    if(s.empty()){
        return;
    }
    string str = "";
    for(int i = 0; i < (int)s.length(); i++){
        if(s[i] == 'b'){
            if(!str.empty()){
                generate(str,m);
                str.clear();
            }
        }
        else{
            str += s[i];
        }   
    }
    if(str == s){
        if(str.find('a') != string::npos){
            m += str.length();
            return;
        }
        return;
    }
    else if(!str.empty()){
        generate(str,m);
    }
}

int main(){
    int n,m = 0;
    cin >> n;
    string s;
    cin >> s;
    generate(s,m);
    cout << m;
}


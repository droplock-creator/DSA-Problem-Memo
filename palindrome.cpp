// A C++ program to check if a given string is a palindrome or not

#include <iostream>
#include <string>
using namespace std;
int main(){
    string s, s_rev;
    cout<<"Enter a string: ";
    getline(cin,s);
    int a=s.size();
    char* c=&s[s.size()-1];
    while(a-->0){
        s_rev.push_back(*c);
        c--;
    }
    if(s==s_rev){
        cout<<"The string is a palindrome."<<endl;
    }
    else{
        cout<<"The string is not a palindrome."<<endl;
    }
    return 0;
}

// Write a cpp program to reverse a string
// Comment out the version you don't wanna use before running the program. You can use either of the two methods to reverse a string. Both of them are equally efficient and work in O(n) time complexity, where n is the length of the string.

// 1. USING LOOPS-:

#include <iostream>
#include <string>
using namespace std;
int main(){
    string s,s_rev;
    cout<<"Enter a string: ";
    getline(cin,s);
    for(int i=s.size()-1;i>=0;i--){
        s_rev.push_back(s[i]);
    }
    cout<<"ORIGINAL STRING: "<<s<<endl;
    cout<<"REVERSED STRING: "<<s_rev<<endl;
    return 0;
}

// 2. USING POINTER-:

#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cout<<"Enter a string: ";
    getline(cin,s);
    char* a=&s[0];
    char *c=&s[s.size()-1];
    while(a<c){
        swap(*a,*c);
        a++;
        c--;
    }
    cout<<"DONE USING POINTER!!"<<endl;
    cout<<"REVERSED STRING: "<<s<<endl;
    return 0;
}

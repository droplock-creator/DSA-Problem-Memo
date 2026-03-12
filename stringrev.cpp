// Write a cpp program to reverse a string

// 1. USING LOOPS-:

// #include <iostream>
// #include <string>
// using namespace std;
// int main(){
//     string s,s_rev;
//     cout<<"Enter a string: "<<endl;
//     getline(cin,s);
//     for(int i=s.size()-1;i>=0;i--){
//         s_rev.push_back(s[i]);
//     }
//     cout<<"ORIGINAL STRING: "<<s<<endl;
//     cout<<"REVERSED STRING: "<<s_rev<<endl;
//     return 0;
// }

// 2. USING POINTER-:

#include <iostream>
#include <string>
using namespace std;
int main(){
    string s,s_rev;
    cout<<"Enter a string: "<<endl;
    getline(cin,s);
    int a=s.size();
    char *c=&s[s.size()-1];
    while(a>0){
        s_rev.push_back(*c);
        c--;
        a--;
    }
    cout<<"DONE USING POINTER!!\n"<<endl;
    cout<<"ORIGINAL STRING: "<<s<<endl;
    cout<<"REVERSED STRING: "<<s_rev<<endl;
    return 0;
}
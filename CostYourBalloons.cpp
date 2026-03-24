/* You are conducting a contest at your college. This contest consists of two problems and 
 participants. You know the problem that a candidate will solve during the contest.

You provide a balloon to a participant after he or she solves a problem. There are only green and purple-colored balloons available in a market. Each problem must have a balloon associated with it as a prize for solving that specific problem. You can distribute balloons to each participant by performing the following operation:

Use green-colored balloons for the first problem and purple-colored balloons for the second problem
Use purple-colored balloons for the first problem and green-colored balloons for the second problem
You are given the cost of each balloon and problems that each participant solve. Your task is to print the minimum price that you have to pay while purchasing balloons.*/

#include<iostream>
using namespace std;
int main(){
    int t;
        cin>>t;
        while(t--){
          int G,P,S,min,max,c2=0;
          cin>>G>>P;
          cin>>S;
          if(G>P){
            max=G;
            min=P;
          }
          else{
            max=P;
            min=G;
          }
          int *Stud=new int[S*2],c1=0,sum=0;
          for(int i=0;i<S*2;i++){
            cin>>Stud[i];
            if(i==0||i%2==0){
              if(Stud[i]==1){
                c1++;
              }
            }
            else if(i%2!=0){
              if(Stud[i]==1){
                c2++;
              }
            }
          }
          if(c1>c2){
            sum=(c1*min)+(c2*max);
          }
          else{
            sum=(c1*max)+(c2*min);
          }
          cout<<sum<<endl;
        }
    }        
#include <iostream>
#include <cmath>
#include <format>
using namespace std;
class Point{
    float x;
    float y;
    public:
        Point(){
            cout<<"Enter X-coordinates of Point: ";
            cin>>x;
            cout<<"Enter Y-coordinates of Point: ";
            cin>>y;
        }    
        Point(float a, float b){
            x=a;
            y=b;
        }
        friend void disp(Point,Point);

};
void disp(Point o1, Point o2){
    float x,y,res;
    x=o1.x-o2.x;
    y=o1.y-o2.y;
    res=sqrt(x*x+y*y);
    cout<<"The distance between ("<<o1.x<<","<<o1.y<<") and ("<<o2.x<<","<<o2.y<<") is: "<<res;
}
 
int main(){
    Point a;
    Point b(7.0,1.0);
    disp(a,b);
    return 0;
}
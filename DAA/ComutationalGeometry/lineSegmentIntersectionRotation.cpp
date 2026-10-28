#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
struct Point{
    long long x,y;
};

long long  dir(Point a, Point b, Point c){
    long long d=((c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x));
    return d;
}
bool onseg(Point a, Point b , Point c){
    if(c.x>=min(a.x,b.x)&&c.x<=max(a.z,b.x)){
        
    }
}
bool intersect(Point a, Point b, Point c, Point d){
    long long d1=dir(a,b,c);
    long long d2=dir(a,b,d);
    long long d3=dir(c,d,a);
    long long d4=dir(c,d,b);
    if((d1>0&& d2<0)||(d1<0&&d2>0)||(d3<0&&d4>0)||(d3>0&&d4<0)){
        return true;
    }

}
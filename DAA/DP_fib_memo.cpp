#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;


//memo ->>> top down ->>> big and then small . so first we try solving big by recurrsive calling solve
int fib(int i,int *memo){
    if(i<=0)return 0;
    if(i==1||i==2)return 1;
    if(memo[i]!=-1)return memo[i];
    memo[i]=fib(i-1,memo)+fib(i-2,memo);
    return memo[i];
}
int findFib(int n){
    int memo[n+1];
    for(int i=0;i<=n;i++){
        memo[i]=-1;
    }
    return fib(n,memo);
}
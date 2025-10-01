#include<stdio.h>
#include<stdlib.h>
void tower(int n,char source,char auxillary,char destination,int *count){
    if(n==0){
        return;
    }
    tower(n-1,source,destination,auxillary,count);
    printf("Move disk %d from %c to %c\n",n,source,destination);
    (*count)++;
    tower(n-1,auxillary,source,destination,count);
}
int main(){
    int n;
    scanf("%d",&n);
    int count=0;
    tower(n,'A','B','C',&count);
    printf("Total number of moves: %d",count);
}
#include<stdio.h>
int *insertion(int *arr,int n){
    if(n<=1){
        return arr;
    }
    else{
        for(int i=1;i<n;i++){
            int j=i-1;
            int key=arr[i];
            while(j>=0 && key<arr[j]){
                arr[j+1]=arr[j];
                j-=1;
            }
        arr[j+1]=key;
        }
    }
    return arr;
}
int main(){
    int arr[5]={5,3,1,2,4};
    insertion(arr,5);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}
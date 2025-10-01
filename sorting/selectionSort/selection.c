#include<stdio.h>
void selection(int *arr,int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
int main(){
    int arr[5]={5,3,1,2,4};
    selection(arr,5);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}
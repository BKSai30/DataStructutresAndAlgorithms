#include<stdio.h>
void sort(int *arr,int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int count[max+1];
    for(int i=0;i<=max;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    int index=0;
    for(int i=0;i<=max;i++){
        while(count[i]>0){
            arr[index++]=i;
            count[i]--;
        }
    }
}

int main(){
    int arr[]={0,2,2,3,4,4,3,1,1,3,4,4,0};
    sort(arr,13);
    for(int i=0;i<13;i++){
        printf("%d ",arr[i]);
    }
}
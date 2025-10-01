#include<stdio.h>
void merge(int *arr,int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int l[n1];
    int r[n2];
    for(int i=0;i<n1;i++){
        l[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        r[i]=arr[mid+i+1];
    }
    int i=0,j=0,k=low;
    while(i<n1&&j<n2){
        if(l[i]<=r[j]){
            arr[k++]=l[i++];
        }
        else if(l[i]>r[j]){
            arr[k++]=r[j++];
        }
    }
    while(i<n1){
        arr[k++]=l[i++];
    }
    while(j<n2){
        arr[k++]=r[j++];
    }
}
void mergesort(int *arr,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int arr[5]={5,4,3,2,1};
    mergesort(arr,0,4);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}
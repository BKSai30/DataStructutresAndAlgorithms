#include<stdio.h>
void swap(int *arr,int i,int j){
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
}
int partition(int *arr,int low,int up){
    int pivot=low+((up-low)/2);
    swap(arr,pivot,up);
    pivot=up;
    int i=low;
    int j=up-1;
    while(i<=j){
        if(arr[i]<arr[pivot]){
            i++;
        }
        else if(arr[j]>arr[pivot]){
            j--;
        }
        else if(i<=j){
            swap(arr,i,j);
            i++;
            j--;
        }
    }
    swap(arr,i,pivot);
    return i;
}
void sort(int *arr,int low,int up){
    if(low<up){
        int mid=partition(arr,low,up);
        sort(arr,low,mid-1);
        sort(arr,mid+1,up);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
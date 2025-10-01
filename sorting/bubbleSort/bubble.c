#include<stdio.h>
void bubble(int*arr,int n){
    for(int i=0;i<n;i++){
        int swap=0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                swap=1;
            }
        }
        if(!swap){
            break;/*since when swap==0 , that sjows that it 
            is already arranged and need not proceed for
            further cases and can break from loop*/
        }
    }
}
int main(){
    int arr[5]={5,3,1,2,4};
    bubble(arr,5);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}
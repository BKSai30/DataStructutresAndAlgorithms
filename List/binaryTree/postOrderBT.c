#include<stdio.h>
#include<stdlib.h>
typedef struct N{
    int data;
    struct N*l;
    struct N*r;
}N;
N*createNode(int data){
    N*node=(N*)malloc(sizeof(N));
    node->l=NULL;
    node->r=NULL;
    node->data=data;
    return node;
}
N*createTree(int arr[],int i,int n){
    if(i>=n){
        return NULL;
    }
    N*node=createNode(arr[i]);
    node->l=createTree(arr,(2*i)+1,n);
    node->r=createTree(arr,(2*i)+2,n);
    return node;
}
void disp(N*head){
    if(head==NULL){
        return;
    }
    if(head->l!=NULL){
        disp(head->l);
    }
    if(head->r!=NULL){
        disp(head->r);
    }
    if(head!=NULL){
        printf("%d ",head->data);
    }
}
int main(){
    int n=5;
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d ",&arr[i]);
    }
    N*tree=createTree(arr,0,n);
    disp(tree);
}
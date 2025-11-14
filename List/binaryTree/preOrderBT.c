#include<stdio.h>
#include<stdlib.h>
typedef struct N{
    int data;
    struct N*l;
    struct N*r;
}N;
N*createNode(int data){
    N*node=(N*)malloc(sizeof(N));
    node->r=NULL;
    node->l=NULL;
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
    N*temp=head;
    if(temp!=NULL){
        printf("%d ",temp->data);
    }
    if(temp->l!=NULL){
        disp(temp->l);
    }
    if(temp->r!=NULL){
        disp(temp->r);
    }
}
int main(){
    int arr[5];
    int n=5;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    N*node=createTree(arr,0,n);
    printf("Preorder traversal:\n");
    disp(node);
    
}
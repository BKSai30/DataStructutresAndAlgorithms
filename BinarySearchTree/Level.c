#include<stdio.h>
#include<stdlib.h>
typedef struct N{
    int data;
    N*r,*l;
}N;
N*createNode(int data){
    N*node=(N*)malloc(sizeof(N));
    node->data=data;
    node->l=node->r=NULL;
    return node;
}
void insert(N**head,int data){
    if(*head==NULL){
        *head=createNode(data);
    }
    else if((*head)->data>=data){
        insert(&(*head)->l,data);
    }
    else if((*head)->data<data){
        insert(&(*head)->r,data);
    }
}
void level(N**head,int x,int *count){
    if(*head==NULL)return;
    if((*head)->data==x){
        return;
    }
    (*count)++;
    if((*head)->data>=x){
        
        level(&(*head)->l,x,count);
    }
    else if((*head)->data<x){
        level(&(*head)->r,x,count);
    }
}


int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    N*head=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        insert(&head,arr[i]);
    }
    int count=0;
    int x;
    scanf("%d",&x);
    level(&head,x,&count);
    printf("%d",count);
}
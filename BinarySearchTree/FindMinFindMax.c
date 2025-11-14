#include<stdio.h>
#include<stdlib.h>
typedef struct N{
    char data;
    N*l,*r;
}N;
N*createNode(char data){
    N*node=(N*)malloc(sizeof(N));
    node->data=data;
    node->r=node->l=NULL;
    return node;
}
void insert(N**head,char data){
    if(!(*head)){
        *head=createNode(data);return;
    }
    if((*head)->data<data){
        insert(&((*head)->r),data);
    }
    else if((*head)->data>=data){
        insert(&((*head)->l),data);
    }
}
void min(N*head){
    N*temp=head;
    while(temp->l!=NULL){
        temp=temp->l;
    }
    printf("Minimum value: %c\n",temp->data);
}
void max(N*head){
    N*temp=head;
    while(temp->r!=NULL){
        temp=temp->r;
    }
    printf("Maximum value: %c\n",temp->data);
}
int main(){
    int n;
    scanf("%d",&n);
    char t;
    N*head=NULL;
    for(int i=0;i<n;i++){
        scanf(" %c",&t);
        insert(&head,t);
    }
    min(head);
    max(head);
}
#include<stdio.h>
#include<stdlib.h>
typedef struct N{
    int data;
    struct N*n;
}N;
N*createNode(int data){
    N*newNode=(N*)malloc(sizeof(N));
    newNode->data=data;
    newNode->n=NULL;
    return newNode;
}
void insertFirst(N**head,int data){
    N*newNode=createNode(data);
    newNode->n=*head;
    *head=newNode;
}
void insertEnd(N**head,int data){
    N*newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    N*temp=*head;
    while(temp->n!=NULL){
        temp=temp->n;
    }
    temp->n=newNode;
}
void insertPosition(N**head,int data,int pos){
    N*newNode=createNode(data);
    if(pos==0){
        insertFirst(head,data);
        return ;
    }
    N*temp=*head;
    pos--;
    while(temp->!=NULL&&pos-->0){
        temp=temp->n;
    }
    if(temp==NULL){
        printf("Out of range\n");
        return;
    }
    newNode->n=temp->n;
    temp->n=newNode;
}
void delFirst(N**head){
    if(*head==NULL){
        printf("List is empty can't delete\n");
        return ;
    }
    N*temp=*head;
    *head=temp->n;
    free(temp);
}
void delEnd(N**head){
    if(*head==NULL){
        printf("List is empty can't delete from the end");
        return;
    }
    N*temp=*head;
    if(temp->n==NULL){
        free(temp);
        *head=NULL;
        return ;
    }
    while(temp->n->n!=NULL){
        temp=temp->n;
    }
    free(temp->n);
    temp->n=NULL;
}
void delPos(N**head,int pos){
    if(*head==NULL){
        printf("List is empty cant delete\n");
        return;
    }
    if(pos==0){
        delFirst(head);
        return;
    }
    pos--;
    N*temp=*head;
    while(temp!=NULL&&pos-->0){
        temp=temp->n;
    }
    if(temp==NULL||temp->n==NULL){
        printf("Out of range\n");
        return;
    }
    N*toDel=temp->n;
    N*next=temp->n->n;
    temp->n=next;
    free(toDel);
}
void disp(N*head){
    if(head==NULL){
        printf("The lis is empty");
        return;
    }
    N*temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->n;
    }
}
int main(){
    N*head=NULL;
    insertEnd(&head,1);
    insertFirst(&head,0);
    insertEnd(&head,2);
    insertEnd(&head,3);
    insertPosition(&head,4,1);
    delFirst(&head);
    delEnd(&head);
    delPos(&head,1);
    disp(head);
}
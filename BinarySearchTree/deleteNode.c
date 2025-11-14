#include<stdio.h>
#include<stdlib.h>
struct N{
    char data;
    struct N*l,*r;
};
struct N*createNode(char data){
    struct N*node=(struct N*)malloc(sizeof(struct N));
    node->data=data;
    node->l=node->r=NULL;
    return node;
}
void insert(struct N**head,char data){
    if(*head==NULL){
        *head=createNode(data);
        return;
    }
    if((*head)->data>=data){
        insert(&(*head)->l,data);
    }
    else if((*head)->data<data){
        insert(&(*head)->r,data);
    }
}
struct N*findMin(N*root){
    N*temp=root;
    while(temp->l!=NULL){
        temp=temp->l;
    }
    return temp;
}
struct N*del(struct N*root, char data){
    if(root==NULL)return root;
    if(root->data>data){
        root->l=del(root->l,data);
    }
    else if(root->data<data){
        root->r=del(root->r,data);
    }
    else{
        if(root->l==NULL){
            struct N*temp=root->r;
            free(root);
            return temp;
        }
        else if(root->r==NULL){
            struct N*temp=root->l;
            free(root);
            return temp;
        }
        struct N*temp=findMin(root->r);
        root->data=temp->data;
        root->r=del(root->r,temp->data);
    }
    return root;
}
void disp(struct N*head){
    if(head==NULL)return;
    disp(head->l);
    printf("%c ",head->data);
    disp(head->r);
}
int main(){
    int n;
    scanf("%d",&n);
    struct N*head=NULL;
    char t;
    for(int i=0;i<n;i++){
        scanf(" %c",&t);
        insert(&head,t);
    }
    scanf(" %c",&t);
    head=del(head,t);
    disp(head);
}
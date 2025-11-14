#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100
int top=-1;
typedef struct N{
    char data;
    N*l,*r;
}N;
N*stack[max];
N*createNode(char data){
    N*node=(N*)malloc(sizeof(N));
    node->l=node->r=NULL;
    node->data=data;
    return node;
}
void push(N*node){
    stack[++top]=node;
}
N*pop(){
    return stack[top--];
}
void createTree(char*arr,int n,N**head){
    for(int i=0;i<n;i++){
        N*node=createNode(arr[i]);
        if(isalnum(arr[i])){
            push(node);
        }
        else{
            N*n2=pop();
            N*n1=pop();
            node->l=n1;
            node->r=n2;
            push(node);
        }
    }
    *head=pop();
}
void disp(N*head){
    if(head==NULL)return;
    if(head->l!=NULL){
        printf("(");
        disp(head->l);
    }
    printf("%c",head->data);
    if(head->r!=NULL){
        disp(head->r);
        printf(")");
    }
}
int main(){
    char arr[max];
    fgets(arr,max,stdin);
    arr[strcspn(arr,"\n")]=0;
    int n=strlen(arr);
    N*head=NULL;
    createTree(arr,n,&head);
    disp(head);
}
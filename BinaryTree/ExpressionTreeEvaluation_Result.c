#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100
int top=-1;
typedef struct N{
    char data;
    N*r,*l;
}N;
N*createNode(char data){
    N*node=(N*)malloc(sizeof(N));
    node->l=node->r=NULL;
    node->data=data;
    return node;
}
N*stack[max];
void push(N*node){
    stack[++top]=node;
}
N*pop(){
    if(top==-1)return NULL;
    return stack[top--];
}
void createTree(char*arr,int n,N**head){
    for(int i=0;i<n;i++){
        if(isdigit(arr[i])){
            N*node=createNode(arr[i]);
            push(node);
        }
        else{
            N*n2=pop();
            N*n1=pop();
            N*node=createNode(arr[i]);
            node->l=n1;
            node->r=n2;
            push(node);
        }
    }
    *head=pop();
}
int result(N*head){
    if(head==NULL)return 0;
    if(isdigit(head->data))return (head->data-'0');
    char a=head->data;
    int n1=result(head->l);
    int n2=result(head->r);
    switch(a){
        case '+':return n1+n2;break;
        case '-':return n1-n2;break;
        case '*':return n1*n2;break;
        case '/':return n1/n2;break;
    }
}
int main(){
    char arr[max];
    fgets(arr,max,stdin);
    arr[strcspn(arr,"\n")]=0;
    int n=strlen(arr);
    N*head=NULL;
    createTree(arr,n,&head);
    printf("Result: %d",result(head));
}
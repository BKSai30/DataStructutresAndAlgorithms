#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define max 100
int top=-1;
int t=-1;
typedef struct N{
    int data;
    N*l,*r;
}N;
N*stack[max];
char s[max];


void pushs(char c){
    s[++t]=c;
}
char pops(){
    return s[t--];
}
char peek(){
    return s[t];
}
int isEmpty(){
    return t==-1;
}


void push(N*head){
    stack[++top]=head;
}
N* pop(){
  return stack[top--];
}
N*createNode(int data){
    N*node=(N*)malloc(sizeof(N));
    node->data=data;
    node->r=node->l=NULL;
    return node;
}
int pre(char c){
    if(c=='^')return 3;
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-')return 1;
}
N*createTree(char*string,int n){
    for(int i=0;i<n;i++){
        if(string[i]!='0'&&string[i]!='\n'&&string[i]!=EOF){
            if(isalpha(string[i])){
                N*node=createNode(string[i]);
                push(node);
            }
            else{
                while(!isEmpty()&&pre(peek())>=pre(string[i])){
                    N*n2=pop();
                    N*n1=pop();
                    N*node=createNode(pops());
                    node->l=n1;
                    node->r=n2;
                    push(node);
                }
                pushs(string[i]);
            }
        }
    }
    while(!isEmpty()){
        N*n2=pop();
        N*n1=pop();
        N*node=createNode(pops());
        node->l=n1;
        node->r=n2;
        push(node);
    }
    return pop();
}
void preOrder(N*head){
    if(head==NULL)return;
    printf("%c",head->data);
    preOrder(head->l);
    preOrder(head->r);
}
void postOrder(N*head){
    if(head==NULL)return;
    postOrder(head->l);
    postOrder(head->r);
    printf("%c",head->data);
}



int main(){
    char string[100];
    fgets(string,100,stdin);
    string[strcspn(string,"\n")]=0;
    int n=strlen(string);
    N*head=createTree(string,n);
    printf("Pre-order Expression: ");
    preOrder(head);
    printf("\nPost-order Expression: ");
    postOrder(head);
}
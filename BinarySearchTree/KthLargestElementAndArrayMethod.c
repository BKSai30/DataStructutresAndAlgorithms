#include<stdio.h>
#include<stdlib.h>
typedef struct N{
    int data;
    N*l,*r;
}N;
N*createNode(int data){
    N*node=(N*)malloc(sizeof(N));
    node->data=data;
    node->l=node->r=NULL;
    return node;
}
N*createTree(int *arr,int n){
    N*root=NULL;
    for(int i=0;i<n;i++){
        N*node=createNode(arr[i]);
        if(root==NULL){
            root=node;
            continue;
        }
        N*temp=root;
        while(1){
            if(temp->data<arr[i]){
                if(temp->r==NULL){
                    temp->r=node;
                    break;
                }
                temp=temp->r;
            }
            else if(temp->data>=arr[i]){
                if(temp->l==NULL){
                    temp->l=node;
                    break;
                }
                temp=temp->l;
            }
        }
    }
    return root;
}
void find(N*node,int*count,int k,int*result){
    if(node==NULL||*count>=k)return;
    
    find(node->r,count,k,result);
    (*count)++;
    if(*count==k){
        *result=node->data;
        return;
    }
    find(node->l,count,k,result);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    N*head=createTree(arr,n);
    int count=0;
    int k;
    scanf("%d",&k);
    int result=-1;
    if(k>n||k<=0)printf("Invalid value of k");
    else{
        find(head,&count,k,&result);
        printf("%d",result);
    }
    
}




#include<stdio.h>
#include<stdlib.h>
typedef struct N{
    int d1;
    int d2;
    struct N*n;
}N;
N*createNode(int d1,int d2){
    N*node=(N*)malloc(sizeof(N));
    node->d1=d1;
    node->d2=d2;
    node->n=NULL;
    return node;
}
void insert(N**head,int d1,int d2){
    N*node=createNode(d1,d2);
    if(*head==NULL){
        *head=node;
        return;
    }
    N*temp=*head;
    while(temp->n!=NULL){
        temp=temp->n;
    }
    temp->n=node;
}
void simple(N**head){
    N*i=*head;
    while(i!=NULL){
        N*j=i;
        while(j->n!=NULL){
            if(i->d2==j->n->d2){
                i->d1+=j->n->d1;
                N*t=j->n;
                j->n=t->n;
                free(t);
            }
            else{
                j=j->n;
            }
        }
        i=i->n;
    }
}
void disp(N**head){
    N*temp=*head;
    int first=1;
    while(temp!=NULL){
        int a=temp->d1;
        int b=temp->d2;
        if(a==0){
            temp=temp->n;
            continue;
        }
        if(!first){
            if(a<0){
                printf("-");
            }
            else{
                printf("+");
            }
            if(b==0){
                printf("%d",abs(a));
            }
            else if(b==1){
                printf("%dx",abs(a));
            }
            else{
                printf("%dx^%d",abs(a),b);
            }
        }
        else if(first){
            first=0;
            if(b==0){
                printf("%d",a);
            }
            else if(b==1){
                printf("%dx",a);
            }
            else{
                printf("%dx^%d",a,b);
            }
        }
        temp=temp->n;
    }
}
void mul(N**h,N**h1,N**h2){
    for(N*i=*h1;i!=NULL;i=i->n){
        for(N*j=*h2;j!=NULL;j=j->n){
            int a=(i->d1)*(j->d1);
            int b=(i->d2)+(j->d2);
            insert(h,a,b);
        }
    }
    
}
void del(N**head,int x){
    N*temp=*head;
    if(temp->d2==x){
        (*head)=temp->n;
        free(temp);
        return;
    }
    while(temp!=NULL &&temp->n!=NULL){
        if(temp->n->d2==x){
            N*t=temp->n;
            temp->n=t->n;
            free(t);
        }
        else{
            temp=temp->n;
        }
    }
}
int main(){
    N*h=NULL,*h1=NULL,*h2=NULL;
    int n1,n2;
    scanf("%d",&n1);
    int a,b;
    for(int i=0;i<n1;i++){
        scanf("%d %d",&a,&b);
        insert(&h1,a,b);
    }
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        scanf("%d %d",&a,&b);
        insert(&h2,a,b);
    }
    int x;
    scanf("%d",&x);
    mul(&h,&h1,&h2);
    simple(&h);
    printf("Result of the Multiplication: ");
    disp(&h);
    printf("\n");
    del(&h,x);
    printf("Result after deleting the term: ");
    disp(&h);
}

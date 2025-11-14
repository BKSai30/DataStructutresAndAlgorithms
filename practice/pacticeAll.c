#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max 100
int main(){
    int V;
    scanf("%d",&V);
    int graph[max][max];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
        scanf("%d",&graph[i][j]);
    
    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        visited[i]=0;
    }
    int parent[max];
    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<V-1;count++){
        int min=INT_MAX;
        int u=-1;
        for(int i=0;i<V;i++){
            if(!visited[i]&&key[i]<min){
                min=key[i];
                u=i;
            }
        }
        visited[u]=1;
        for(int v=0;v<V;v++){
            if(!visited[v]&&graph[u][v]&&graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }
    for(int i=1;i<V;i++){
        printf("%d %d %d\n",parent[i],i,graph[i][parent[i]]);
    }
}
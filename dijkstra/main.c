#include <stdio.h>
#include <stdlib.h>

void Dijkstra(int D[10][10],int,int);
int main()
{
   int dist_graph[10][10],n,start;
   printf("Enter the number of nodes: ");
   scanf("%d",&n);
   printf("\n\nEnter the starting node: ") ;
   scanf("%d",&start);
   printf("\n\nEnter the direct distance to nodes:\n");
   for(int i = 0;i<n;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&dist_graph[i][j]);
    }
   }

   Dijkstra(dist_graph,n,start-1);
}
void Dijkstra(int D[10][10],int n,int start){
    int cost[10][10],dist[10],visited[10],pred[10];
    int i,j,counter,mindist,next;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(D[i][j]==0){
                cost[i][j]=100000;
            }else{
              cost[i][j] = D[i][j];
            }
        }
    }
    for(i=0;i<n;i++){
        dist[i]=cost[start][i];
        pred[i]=start;
        visited[i] = 0;
    }
    dist[start]=0;
    visited[start]=1;
    counter = 1;
    while(counter<(n-1)){
            mindist = 100000;
        for(i=0;i<n;i++){
            if((dist[i]<mindist)&& !visited[i]){
                 mindist = dist[i];
                 next = i;
            }
        }
        visited[next] = 1;
        for(i=0;i<n;i++){
            if(!visited[i]){
                if((mindist+cost[next][i])<dist[i]){
                    dist[i] = mindist+cost[next][i];
                    pred[i]=next;
                }
            }
        }
        counter++;
    }
    for(i=0;i<n;i++){
        if(i!=start){
            printf("\nThe distance to node %d from %d is %d\n",i,start,dist[i]);
            printf("The path is %d",i);
            j=i;
            do{
                j=pred[j];
                printf(" <- %d",j);
            }while(j!=start);
        }
        printf("\n");
    }
}

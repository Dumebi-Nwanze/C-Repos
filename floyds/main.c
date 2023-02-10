#include <stdio.h>
#include <stdlib.h>

int min(int a,int b){
 int min = a<b ? a: b;
 return min;
}
void printMatrix(int i,int j,int A[i][j])
{
    int m,n;
    for (m=0;m<i;m++)
        {
            for (n=0;n<j;n++)
            {
                printf("%7d",A[m][n]);
            }  printf("\n");
        }
}
void FloydPath(int i,int j,int A[][j])
{
    int m,n,k,c1,c2;
    int temp[i][j];//length matrix
    int temp2[i][j];//path matrix
    for(m=0;m<i;m++){// pass matrix values to the matrix in the function scope
        for(n=0;n<j;n++){
            temp[m][n] = A[m][n];
        }
    }
    for(m=0;m<i;m++){// initialization of path matrix
        for(n=0;n<j;n++){
            temp2[m][n] = n+1;
        }
    }
    printf("\n");
    for(k=0;k<j;k++){
        for(m=0;m<j;m++){
            for(n=0;n<j;n++){
                if(m==k||n==k){// leave values same if they are in selected k crossing
                    temp[m][n]=temp[m][n];
                }
                else{//change the selected cell using the Floyd formula
                     c1 = temp[m][n];//previous variables are stored before update
                    c2 = temp[m][k]+temp[k][n];
                    temp[m][n] = min(temp[m][n],(temp[m][k]+temp[k][n]));
                    if(c1>c2){//checking the algorithm condition
                        temp2[m][n] = temp2[m][k];
                    }
                }
            }
        }
    }

    printMatrix(m,n,temp);
    printf("\n\n\n");
    printMatrix(m,n,temp2);
    int s,e;
    printf("\nShortest path of selected node...\n");

    printf("Enter starting node: ");
    scanf("%d",&s);
    printf("\nEnter ending node: ");
    scanf("%d",&e);
    printf("Length of the shortest path = %d\n\n",temp[s][e]);
    printf("Path = %d -> ",s);
        while(temp2[s-1][e-1]!= e){
            printf("%d -> ",temp2[s-1][e-1]);
            s = temp2[s-1][e-1];
    }
    printf("%d\n",e);

}

int main()
{
    int n,c,i,j;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    printf("\n");
    i = j = n;
    int D[i][j];
    for(i = 0; i<n;i++){
        for(j = 0; j<n;j++){
            if(i==j){
                D[i][j] = 10000;// selected infinity value
            }
            else{
                printf("Enter the value for node %d to node %d\n",i+1,j+1);
                printf("!!In case of no value input 10000!!\n");
                scanf("%d",&c);
                D[i][j] = c;
            }
        }
    }
    FloydPath(i,j,D);
    return 0;
}

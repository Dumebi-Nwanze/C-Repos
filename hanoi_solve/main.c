#include <stdio.h>
void print(int start, int dest){
     printf("Disk on %d moves to peg %d\n\n",start,dest);
}
void hanoi_solve(int n, int first, int last)
{

    if(n==1){
        print(first,last);
    }
    else{
int middle = 6 -(first+last);
        hanoi_solve(n-1,first,middle);
        print(first,last);
        hanoi_solve(n-1,middle,last);
    }
}
int main()
{
    hanoi_solve(4,1,3);
}

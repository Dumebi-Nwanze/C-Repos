
#include<stdio.h>
#include<math.h>
int a[30];//position array
int position(int pos)
{
 int i;
 for(i=1;i<pos;i++)
 {
  if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
   return 0;
 }
 return 1;
}
void print_sol(int n)
{
 int i,j,count;
 count++;
 printf("\n\nCombination No.%d:\n",count);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(a[i]==j)
    printf("1\t");
   else
    printf("0\t");
  }
  printf("\n");
 }
}
int queen(int n)
{
 int count = 0;
 int k=1;
 a[k]=0;
 while(k!=0)
 {
  do
  {
    a[k]++;
  }while((a[k]<=n)&&(position(k)==0));
  if(a[k]<=n)
  {
   if(k==n){
    print_sol(n);
    count++;
   }
   else
   {
    k++;
    a[k]=0;
   }
  }
  else
   k--;
 }
 return count;
}
int main()
{
    int n = 27;

 printf("\nNumber of combinations for %d queens = %d",n,queen(n));
 return 0;
}

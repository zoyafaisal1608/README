#include<stdio.h>
void main()
{
int n,a[10],i,j,temp;
printf("enter size:");
scanf("%d",&n);
printf("enter the elements:\n");
for(i=0;i<n;i++)
{
  scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
   for(j=0;j<n-i-1;j++)
  {
    if(a[j]>a[j+1])
    {
       temp=a[j];
       a[j]=a[j+1];
       a[j+1]=temp;
    }
  }
}
printf("sorted elements are:\n");
for(i=0;i<n;i++)
  {
   printf("%d",a[i]);
  }
}

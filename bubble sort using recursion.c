#include<stdio.h>
int a[10],n;
void bubblesort(int n)
{
int i,temp;
if(n==1)
return;
for(i=0;i<n-1;i++)
{
if(a[i]>a[i+1])
{
temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
}
}
bubblesort(n-1);
}
void main()
{
int i;
printf("enter size:");
scanf("%d",&n);
printf("enter the elements:\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
bubblesort(n);
printf("sorted elements:\n");
for(i=0;i<n;i++)
{
printf("%d",a[i]);
}
}

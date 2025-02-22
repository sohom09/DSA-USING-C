#include<stdio.h>
void swap(int x[],int i1,int i2)
{
	int t=x[i1];
	x[i1]=x[i2];
	x[i2]=t;
}
void quicksort(int x[],int st,int nd,int si)
{
	if(st<nd)
	{
		for (int i=st;i<nd;i++)
		{
			if(x[i]<x[nd])
				swap(x,i,si++);
		}
		swap(x,si,nd);
		quicksort(x,0,si-1,0);
		quicksort(x,si+1,nd,si+1);
	}
}
int main()
{
	int ar[]={45,12,72,33,42,72,35,90,19,40};
	int len=sizeof(ar)/sizeof(ar[0]);
	printf("\n---Before Sorting----\n\n");
	for (int i=0;i<len;i++)
		printf("%d\t",ar[i]);
	quicksort(ar,0,len-1,0);
	printf("\n---After Sorting----\n\n");
	for (int i=0;i<len;i++)
		printf("%d\t",ar[i]);
}

#include<stdio.h>
int ar[]={3,5,21,7,2,12,8,90};
int len=sizeof(ar)/sizeof(ar[0]),last=len-1;
void swap(int x[],int a,int b)
{
	int t=x[a];
	x[a]=x[b];
	x[b]=t;
}
void heapify(int x[],int p,int lc,int rc)
{
	if (lc<=last)
	{
		heapify(x,lc,lc*2+1,lc*2+2);
		if (x[lc]>x[p])
			swap(x,lc,p);
	}
	if (rc<=last)
	{
		heapify(x,rc,rc*2+1,rc*2+2);
		if (x[rc]>x[p])
			swap(x,rc,p);
	}
}
void heapsort(int x[])
{
	if (last>0)
	{
		heapify(x,0,1,2);
		swap(x,0,last--);
		heapsort(x);
	}
}
int main()
{
	heapsort(ar);
	for (int i=0;i<len;i++)
		printf("%d ",ar[i]);
}

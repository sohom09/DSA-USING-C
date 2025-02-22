//MEREGE SORT 
#include<stdio.h>
int a[]={90,45,78,25,78,88,43,56,10,22,47,66,40};
int b[sizeof(a)/sizeof(a[0])];
void sort(int s,int m,int e)
{
	int i=s,j=m+1,si=s;
	if(s<e)
	{
		while(i<=m && j<=e)
		{
			if (a[i]<a[j])
				b[si++]=a[i++];
			else
				b[si++]=a[j++];
		}
		for (int k=i;k<=m;k++)
			b[si++]=a[k]; //left array fillup
		for (int k=j;k<=e;k++)
			b[si++]=a[k]; //right array fillup
		for (int k=s;k<=e;k++)
			a[k]=b[k]; //sorted array overwrite
		
	}
}
void divide(int st,int en) // 0-7
{
	if(st<en)
	{
		int md=(st+en)/2;
		divide(st,md);
		divide(md+1,en);
		sort(st,md,en);
	}
}
int main()
{
	int start=0, end=sizeof(a)/sizeof(a[0]) -1;
	for(int i=0;i<=end;i++)
		printf("%d ",a[i]);
	printf("\n---AFTER MERGESORT---\n");
	divide(start,end);
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
			printf("%d ",a[i]);
}

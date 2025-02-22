#include<stdio.h>
int binsrch(int *x,int d,int l,int h)
{
	int mid=(l+h)/2;
	if(l<=h)
	{
		if(x[mid]==d)
			return mid;
		else if(x[mid]<d)
			binsrch(x,d,mid+1,h);
		else
			binsrch(x,d,l,mid-1);
	}
	else
		return -1;
}
int main()
{
	int size;
	printf("ENTER SIZE: ");
	scanf("%d",&size);
	int ar[size];
	printf("\nENTER DATA(ELEMENTS)INTO THE ARRAY TO PERFORM BINARY SEARCH: ");
	for(int i=0;i<size;i++)
	{
		printf("\nENTER DATA[%d]: ",i);
		scanf("%d",&ar[i]);
	}
	printf("\n\n---YOUR ARRAY:----\n");
	for(int i=0;i<size;i++)
	{
		printf("%d\t",ar[i]);
	}
	for(int i=0;i<size;i++)
	{
		for(int j=i;j<size;j++)
		{
			if(ar[i]>ar[j])
			{
				int temp;
				temp=ar[i];
				ar[i]=ar[j];
				ar[j]=temp;
			}
		}
	}
	printf("\n\n---YOUR SORTED ARRAY:---\n\n");
	for(int i=0;i<size;i++)
	{
		printf("%d\t",ar[i]);
	}
	int sd,li=0,hi=sizeof(ar)/sizeof(ar[0]);
	printf("\nENTER SEARCH DATA: ");
	scanf("%d",&sd);
	if(binsrch(ar,sd,li,hi)==-1)
		printf("\nNOT FOUND!!");
	else
		printf("\nFound at position: %d",binsrch(ar,sd,li,hi));
	
	
}

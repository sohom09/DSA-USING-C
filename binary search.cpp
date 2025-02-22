#include<stdio.h>
int main()
{
	int size;
	printf("Enter size:");
	scanf("%d",&size);
	int ar[size];
	for(int i=0;i<size;i++)
	{
		printf("Enter data[%d]: ",i);
		scanf("%d",&ar[i]);
		
	}
	printf("\n\nYOUR ARRAY:\n ");
	for(int i=0;i<size;i++)
	{
		printf("%d \t",ar[i]);
	}
	for(int i=0;i<=size;i++)
	{
		for(int j=i;j<=size;j++)
		{
			if(ar[i]>ar[j])
			{
				int temp=ar[i];
				ar[i]=ar[j];
				ar[j]=temp;
			}
		}
	}
	printf("\n----------------------------------------------\n");
	printf("\n\nYOUR SORTED ARRAY:\n ");
	for(int i=0;i<size;i++)
	{
		printf("%d \t",ar[i]);
	}
	int n,l=0,u=size-1,mid,flag=-1;
	printf("\n\n Enter SEARCH DATA: ");
	scanf("%d",&n);
	while(l<=u)
	{
		mid=(l+u)/2;
		if(ar[mid]==n)
		{
			flag=mid;
			break;
		}
		else if(n<ar[mid])
			u=mid-1;
		else
			l=mid+1;
		
	}
	if(flag==-1)
		printf("\nNOT FOUND!");
	else
		printf("\n FOUNDED AT %d POSITION ",flag);
return 0;
		
}

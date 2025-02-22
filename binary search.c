#include<stdio.h>
int main()
{
	int size,i;
	printf("Enter size:");
	scanf("%d",&size);
	int ar[size];
	for(i=0;i<size;i++)
	{
		printf("Enter data[%d] in a sorted order: ",i);
		scanf("%d",&ar[i]);
		
	}
	printf("YOUR SORTED ARRAY:\n ");
	for(i=0;i<size;i++)
	{
		printf("%d\t",ar[i]);
	}
	int n,l=0,u=size-1,mid,flag=-1;
	printf("\n Enter SEARCH DATA: ");
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
		printf("NOT FOUND!");
	else
		printf("\n FOUNDED AT %d POSITION: ",flag);
return 0;
}

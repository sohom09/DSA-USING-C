#include<stdio.h>
#include<stdlib.h>
int *create(int s)
{
	int *ar=(int*)malloc(s*sizeof(int));
	for(int i=0;i<s;i++)
	{
		printf("\nENTER DATA[%d] : ",i);
		scanf("%d",&ar[i]);
	}
	return ar;
}
void display(int ar[],int s)
{
	printf("\n\nYOUR ARRAY: ");
	for(int i=0;i<s;i++)
		printf("%d\t",ar[i]);
}
int arsum(int ar[],int s)
{
	int sum=0;
	for(int i=0;i<s;i++)
	{
		sum+=ar[i];
	}
	return sum;
	
}
int main()
{
	int size;
	printf("\nENTER SIZE: ");
	scanf("%d",&size);
	int *x=create(size);
	display(x,size);
	printf("\nSUM OF ALL THE ELEMENTS: %d",arsum(x,size));
	
}

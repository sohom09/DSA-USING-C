#include<stdio.h>
int ARMIN(int *d,int x)
{
	int min=d[0];
	for(int i=0;i<x;i++)
	{
		if(d[i]<min)
			min=d[i];
	}
	return min;
}
int ARMAX(int *d,int x)
{
	int max=d[0];
	for(int i=0;i<x;i++)
	{
		if(d[i]>max)
			max=d[i];
	}
	return max;
}
int ARSUM(int *d,int x)
{
	int sum=0;
	for(int i=0;i<x;i++)
	{
		sum=sum+d[i];
	}
	return sum;
}
int main()
{
	int size;
	printf("Enter Size: ");
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<size;i++)
	{
		printf("Enter data[%d]: ",i);
		scanf("%d",&arr[i]);
	}
	printf("\n YOUR ARRAY: \n ");
	for(int i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n\nMAXIMUM ELEMENT IN THE ARRAY: %d ",ARMAX(arr,size));
	printf("\nMINIMUM ELEMENT IN THE ARRAY: %d ",ARMIN(arr,size));
	printf("\nADDITION OF THE ELEMENTS IN THE ARRAY: %d ",ARSUM(arr,size));
}

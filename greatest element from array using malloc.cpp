#include<stdio.h>
#include<stdlib.h>
int grt(int *x,int s)
{
	int greater=x[0];
	for(int i=1;i<s;i++)
	{
		if(x[i]>greater)
			greater=x[i];
	}
	return greater;
}
int main()
{
	int size;
	printf("ENTER SIZE OF THE ARRAY: ");
	scanf("%d",&size);
	int *ar=(int*)malloc(size*sizeof(int));
	for(int i=0;i<size;i++)
	{
		printf("\nENTER DATA[%d]: ",i);
		scanf("%d",&ar[i]);
	}
	printf("\n\n---YOUR ARRAY ELEMENTS---:\n ");
	for(int i=0;i<size;i++)
	{
		printf("%d\t",ar[i]);
	}
	printf("\nLargest element of the array using dma: %d ",grt(ar,size));
}

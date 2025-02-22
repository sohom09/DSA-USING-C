#include<stdio.h>
void swap1(int a , int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	printf("\nCall by value: ");
	printf("\nValue of A: %d\tValue of B: %d",a,b);
}
void swap2(int *a , int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	printf("\nCall by reference: ");
	printf("\nValue of A: %d\tValue of B: %d",*a,*b);
}
int main()
{
	int n1,n2;
	printf("\nEnter the two numbers: ");
	scanf("%d %d",&n1,&n2);
	printf("\nValue before swapping: ");
	printf("\nValue of A: %d\tValue of B: %d",n1,n2);
	swap1(n1,n2);
	swap2(&n1,&n2);
}

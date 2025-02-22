#include<stdio.h>
#define size 5
int ar[size],i,top=-1;
void push()
{
	if(top==size-1)
	{
		printf("OVERFLOW\n");
	}
	else
	{
		printf("Enter data[%d]: ",i);
		scanf("%d",&ar[++top]);
	}
}
void pop()
{
	if(top==-1)
		printf("\nUNDERFLOW");
	else
		printf("\n%d has been deleted ",ar[top--]);
}
void disp()
{
	if(top==-1)
		printf("\nEMPTY STACK");
	else
	{
		for(int i=top;i>=0;i--)
			printf("%d\n",ar[i]);
	}
		
}
int main()
{
	int ch;
	printf("\n1.PUSH()\n2.POP()\n3.DISPLAY()\n4.EXIT");
	printf("\n\nEnter choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			push();
			
		case 2:
			pop();
			
		case 3:
			disp();
			
		case 4:
			break;
		default:
			printf("\n-----INVALID CHOICE-----");
			
	}
	
}

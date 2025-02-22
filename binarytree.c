#include<stdio.h>
#define size 20
char tree[size];
int getpi(char p)
{
	for (int i=0;i<size;i++)
	{
		if (tree[i]==p)
			return i;
	}
	return -1;
}
void root(char node)
{
	if (tree[0]!='\0')
		printf("\nAlready have a root");
	else
		tree[0]=node;
}
void insL(char node,int pi)
{
	if (tree[2*pi+1]!='\0')
		printf("\nAlready exists");
	else
		tree[2*pi+1]=node;
}
void insR(char node,int pi)
{
	if (tree[2*pi+2]!='\0')
		printf("\nAlready exists");
	else
		tree[2*pi+2]=node;
}
void treedisp()
{
	if (tree[0]=='\0')
		printf("\nTree doesn't exist");
	else
	{
		for (int i=0;i<size;i++)
		{
			if (tree[i]=='\0')
				printf("_ ");
			else
				printf("%c ",tree[i]);
		}
	}
}
int main()
{
	printf("\n1. Enter root\n2. Enter left\n3. Enter right\n4. Display\n0. Exit");
	while(1)
	{
		int ch;
		printf("\nEnter choice:");
		scanf("%d",&ch);
		if (ch==1)
		{
			char d;
			printf("\nEnter root:");
			getchar();
			scanf("%c",&d);
			root(d);
		}
		else if (ch==2)
		{
			char d,p;
			printf("\nEnter LC:");
			getchar();
			scanf("%c",&d);
			printf("\nEnter parent:");
			getchar();
			scanf("%c",&p);
			if (getpi(p)==-1)
				printf("\nParent Not Found");
			else
				insL(d,getpi(p));
		}
		else if (ch==3)
		{
			char d,p;
			printf("\nEnter RC:");
			getchar();
			scanf("%c",&d);
			printf("\nEnter parent:");
			getchar();
			scanf("%c",&p);
			if (getpi(p)==-1)
				printf("\nParent Not Found");
			else
				insR(d,getpi(p));
		}
		else if (ch==4)
			treedisp();
		else if (ch==0)
			break;
		else
			printf("\nInvalid choice");
	}
}
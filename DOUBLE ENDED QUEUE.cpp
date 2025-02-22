#include<stdio.h>
#define size 5
int ar[size],f=-1,r=-1;
void insr()
{
	if ((r+1)%size==f)
		printf("\nOverflow");
	else if (r==-1)
	{
		f=r=0;
		printf("\nEnter data:");
		scanf("%d",&ar[r]);
	}
	else if (r==size-1)
	{
		r=0;
		printf("\nEnter data:");
		scanf("%d",&ar[r]);
	}
	else
	{
		printf("\nEnter data:");
		scanf("%d",&ar[++r]);
	}
}
void insf()
{
	if ((r+1)%size==f)
		printf("\nOverflow");
	else if (f==-1)
	{
		f=r=0;
		printf("\nEnter data:");
		scanf("%d",&ar[f]);
	}
	else if(f==0)
	{
		f=size-1;
		printf("\nEnter data:");
		scanf("%d",&ar[f]);
	}
	else
	{
		printf("\nEnter data:");
		scanf("%d",&ar[--f]);
	}
}
void delr()
{
	if (r==-1)
		printf("\nUnderflow");
	else if(f==r)
	{
		printf("\n%d has been deleted",ar[r]);
		f=r=-1;
	}
	else if (r==0)
	{
		printf("\n%d has been deleted",ar[r]);
		r=size-1;
	}
	else
		printf("\n%d has been deleted",ar[r--]);
}
void delf()
{
	if (f==-1)
		printf("\nUnderflow");
	else if(f==r)
	{
		printf("\n%d has been deleted",ar[f]);
		f=r=-1;
	}
	else if (f==size-1)
	{
		printf("\n%d has been deleted",ar[f]);
		f=0;
	}
	else
		printf("\n%d has been deleted",ar[f++]);
}
void disp()
{
	if (f==-1)
		printf("\nQueue empty");
	else
	{
		int i=f;
		do
		{
			printf("%d--%d\t",i,ar[i]);
			i=(i+1)%size;
		}while(i!=(r+1)%size);
	}
}
int main()
{
	printf("\n1. Insr\n2. Insf\n3. delr\n4. delf\n5. disp\n0. Exit");
	while (1)
	{
		int ch;
		printf("\nEnter choice:");
		scanf("%d",&ch);
		if (ch==1)
			insr();
		else if (ch==2)
			insf();
		else if (ch==3)
			delr();
		else if (ch==4)
			delf();
		else if (ch==5)
			disp();
		else if (ch==0)
			break;
		else
			printf("\nINVALID CHOICE");
	}
}

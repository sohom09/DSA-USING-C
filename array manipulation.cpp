#include<stdio.h>
#define size 5
int ar[size],t=-1;
void insbeg()
{
	if (t==size-1)
		printf("\nOverflow");
	else
	{
		for (int i=t;i>=0;i--)
			ar[i+1]=ar[i];
		printf("\nEnter data:");
		scanf("%d",&ar[0]);
		t++;
		
	}
}
void insend()
{
	if(t==size-1)
		printf("\nOverflow");
	else
	{
		printf("\nEnter data:");
		scanf("%d",&ar[++t]);
	}
}
void delbeg()
{
	if (t==-1)
		printf("\nUnderflow");
	else
	{
		printf("\n%d has been deleted.",ar[0]);
		for (int i=1;i<=t;i++)
			ar[i-1]=ar[i];
		t--;
	}
}
void delend()
{
	if (t==-1)
		printf("\nUnderflow");
	else
		printf("\n%d has been deleted.",ar[t--]);
}
int lnsrch()
{
	if (t==-1)
		printf("\nEmpty");
	else
	{
		int d,f=-1;
		printf("\nEnter data to search:");
		scanf("%d",&d);
		for (int i=0;i<=t;i++)
		{
			if(ar[i]==d)
			{
				f=i;
				break;
			}	
		}
		if (f==-1)
			printf("\nNot found");	
		else
			printf("\nFound at %d index",f);
		return f;
	}
}
void inspos()
{
	if (t==size-1)
		printf("\nOverflow");
	else
	{
		int pos;
		entrypos:
			printf("\nEnter index:");
			scanf("%d",&pos);
		if (pos<0 || pos>t)
		{
			printf("\nRange: 0 -> %d",t);
			goto entrypos;
		}
		for (int i=t;i>=pos;i--)
			ar[i+1]=ar[i];
		printf("\nEnter data:");
		scanf("%d",&ar[pos]);
		t++;
	}
}
void disp()
{
	if(t==-1)
		printf("\nEmpty");
	else
	{
		for (int i=0;i<=t;i++)
			printf("%d\t",ar[i]);
	}
}
void delpos()
{
	if (t==-1)
		printf("\nUnderflow");
	else
	{
		int pos;
		entrypos:
			printf("\nEnter index:");
			scanf("%d",&pos);
		if (pos<0 || pos>t)
		{
			printf("\nRange: 0 -> %d",t);
			goto entrypos;
		}
		printf("\n%d has been deleted.",ar[pos]);
		for (int i=pos+1;i<=t;i++)
			ar[i-1]=ar[i];
		t--;
	}
}
void deldata() // deldata = lnsrc + delpos
{
	if (t==-1)
		printf("\nUnderflow");
	else
	{
		int fpos=lnsrch();
		
		if (fpos>-1)
		{
			printf("\n%d has been deleted.",ar[fpos]);
			for (int i=fpos+1;i<=t;i++)
				ar[i-1]=ar[i];
			t--;
		}
	}
}
int main()
{
	printf("\n1. Insert at beginning\n2. Insert at ending");
	printf("\n3. Delete from beginning\n4. Delete from ending");
	printf("\n5. Display\n6. Linear Search");
	printf("\n7. Insert by index\n8. Delete by index");
	printf("\n9. Delete by data\n0. Exit");
	while(1)
	{
		int ch;
		printf("\nEnter choice:");
		scanf("%d",&ch);
		if (ch==1)
			insbeg();
		else if(ch==2)
			insend();
		else if (ch==3)
			delbeg();
		else if (ch==4)
			delend();
		else if (ch==5)
			disp();
		else if (ch==6)
			lnsrch();	
		else if (ch==7)
			inspos();
		else if (ch==8)
			delpos();
		else if (ch==9)
			deldata();
		else if (ch==0)
			break;
		else
			printf("\n---INVALID CHOICE---");
	}
}

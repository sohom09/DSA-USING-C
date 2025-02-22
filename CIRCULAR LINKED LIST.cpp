//CIRCULAR LINKED LIST
#include<stdio.h>
#include<malloc.h>
struct node{
	int d;
	struct node *next;
};
struct node *last=NULL;
void insbeg()
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d",&n->d);
	if(last==NULL)
	{
		last=n;
		last->next=last;
	}
	else
	{
		n->next=last->next;
		last->next=n;
	}
}
void insend()
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d",&n->d);
	if(last==NULL)
	{
		
		last=n;
		last->next=last;
	}
	else
	{
		n->next=last->next;
		last->next=n;
		last=n;
	}
}
int getnode()
{
	int x=0;
	if(last==NULL)
	{
		return x;
	}
	else
	{
		struct node *p=last->next;
		while(p!=last)
		{
			p=p->next;
			x++;
		}
		return x+1;
	}
}
void inspos()
{
	int pos;
	printf("\nEnter position:");
	scanf("%d",&pos);
	if (pos<0 || pos>getnode())
		printf("\nInvalid position");
	else if (pos==0)
	{
		struct node *n=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data: ");
		scanf("%d",&n->d);
		n->next=last->next;
		last->next=n;
	}
	else
	{
		struct node *n=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data: ");
		scanf("%d",&n->d);
		struct node *p=last->next;
		for (int i=1;i<pos;i++)
			p=p->next;
		n->next=p->next;
		p->next=n;
	}
}
void delbeg()
{
	if(last==NULL)
		printf("\nUNDERFLOW");
	else if(last->next==last)
	{
		struct node *dt=last;
		printf("\n%d has been deleted",dt->d);
		free(dt);
		last=NULL;
	}
	else
	{
		struct node *dt=last->next;
		last->next=last->next->next;
		printf("\n%d has been deleted",dt->d);
		free(dt);
	}
}
void delend()
{
	if(last==NULL)
		printf("\nUNDERFLOW");
	else if(last->next==last)
	{
		struct node *dt=last;
		printf("\n%d has been deleted",dt->d);
		free(dt);
		last=NULL;
	}
	else
	{
		struct node *p=last->next;
		struct node *del=last;
		while(p->next!=last)
		{
			p=p->next;
		}
		p->next=last->next;
		printf("\n%d has been deleted",del->d);
		free(del);
		last=p;
	}
}
void delpos()
{
	int pos;
	printf("\nEnter position:");
	scanf("%d",&pos);
	if (pos<0 || pos>=getnode())
		printf("\nInvalid position");
	else if (pos==0)
	{
		struct node *dt=last->next;
		last->next=dt->next;
		printf("\n%d has been deleted",dt->d);
		free(dt);
	}
	else
	{
		struct node *p=last->next;
		for (int i=1;i<pos;i++)
			p=p->next;
		struct node *del=p->next;
		printf("\n%d has been deleted",del->d);
		p->next=del->next;
		free(del);
	}
	
}
void disp()
{
	if(last==NULL)
		printf("\nCIRCULAR LL EMPTY");
	else
	{
		struct node *p=last->next;
		printf("\n ... ");
		do
		{
			printf("%d\t --> ",p->d);
			p=p->next;
		}while(p!=last->next);
		printf(" ... ");
	}
}
int main()
{
	printf("\n1. Insert at begining\n2. Insert at ending\n3. Count the number of nodes\n4. Delete from beginning\n5. Delete from ending\n6. Display\n7. Insert by position\n8. Delete by position\n0. Exit");
	while(1)
	{
		int ch;
		printf("\nEnter choice:");
		scanf("%d",&ch);
		if (ch==1)
			insbeg();
		else if (ch==2)
			insend();
		else if(ch==3)
			printf("\nNumber of nodes: %d",getnode());
		else if (ch==4)
			delbeg();
		else if (ch==5)
			delend();
		else if (ch==6)
			disp();
		else if (ch==7)
			inspos();
		else if (ch==8)
			delpos();
		else if (ch==0)
			break;
		else
			printf("\nINVALID");
	}
}


#include<stdio.h>
#include<malloc.h>
struct node{
	int d;
	struct node *next;
};

struct node *head=NULL;
void insbeg()
{
	struct node *n=(struct node*)malloc(sizeof(struct node)); //var=(target*)malloc(size)
	printf("\nEnter data:");
	scanf("%d",&n->d);
	if (head==NULL)
	{
		head=n;
		n->next=NULL;
	}
	else
	{
		n->next=head;
		head=n;
	}		
}
int getnode()
{
	int x=0;
	if (head==NULL)
		return x;
	else
	{
		struct node *p=head;
		while(p!=NULL)
		{
			p=p->next;
			x++;
		}
		return x;
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
		printf("\nEnter data:");
		scanf("%d",&n->d);
		n->next=head;
		head=n;
	}
	else
	{
		struct node *n=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter data:");
		scanf("%d",&n->d);
		struct node *p=head;
		for (int i=1;i<pos;i++)
			p=p->next;
		n->next=p->next;
		p->next=n;
	}
}
void insend()
{
	struct node *n=(struct node*)malloc(sizeof(struct node)); //var=(target*)malloc(size)
	printf("\nEnter data:");
	scanf("%d",&n->d);
	if (head==NULL)
	{
		head=n;
		n->next=NULL;
	}
	else
	{
		struct node *p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=n;
		n->next=NULL;
	}
}
void delbeg()
{
	if (head==NULL)
		printf("\nUNDERFLOW");
	else
	{
		struct node *dt=head;
		head=head->next;
		printf("\n%d has been deleted",dt->d);
		free(dt);
	}
}
void delend()
{
	if (head==NULL)
		printf("\nUNDERFLOW");
	else
	{
		struct node *p=head;
		struct node *pr;
		while(p->next!=NULL)
		{
			pr=p;
			p=p->next;
		}
		printf("\n%d has been deleted.",p->d);
		free(p);
		pr->next=NULL;
	}
}
void disp()
{
	if (head==NULL)
		printf("\nLL EMPTY");
	else
	{
		struct node *p=head;
		while(p!=NULL)
		{
			printf("%d\t",p->d);
			p=p->next;
		}
	}
}
void revdisp()
{
	if (head==NULL)
		printf("\nEmpty LL");
	else
	{
		struct node *last=NULL;
		while(head!=last)
		{
			struct node *t=head;
			while(t->next!=last)
				t=t->next;
			printf("%d\t",t->d);
			last=t;
		}
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
		struct node *del=head;
		head=head->next;
		free(del);
	}
	else
	{
		struct node *p=head;
		for (int i=1;i<pos;i++)
			p=p->next;
		struct node *del=p->next;
		p->next=del->next;
		free(del);
	}
	
}
int main()
{
	printf("\n1. Insert at the beginning\n2. Insert at ending\n3. Insert position wise \n4. Getnode \n5. Delete from beginning\n6. Delete from ending  \n7. Delete position wise \n8. Forward Display\n9. Reverse Display \n0. Exit");
	while(1)
	{
		int ch;
		printf("\nEnter choice:");
		scanf("%d",&ch);                             
		if (ch==1)
			insbeg();
		else if (ch==2)
			insend();
		else if (ch==3)
			inspos();
		else if (ch==4)
			printf("\nTotal nodes: %d",getnode());
		else if (ch==5)
			delbeg();
		else if (ch==6)
			delend();
		else if (ch==7)
			delpos();
		else if (ch==8)
			disp();
		else if (ch==9)
			revdisp();
		else if (ch==0)
			break;
		else
			printf("\nINVALID");
	}
}

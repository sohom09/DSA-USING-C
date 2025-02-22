//DOUBLY LINKED LIST
#include<stdio.h>
#include<malloc.h>
struct node{
	int d;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
void insbeg()
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	printf("\nENTER DATA: ");
	scanf("%d",&n->d);
	if(head==NULL)
	{
		head=n;
		n->next=NULL;
		n->prev=NULL;
	}
	else
	{
		n->next=head;
		head->prev=n;
		head=n;
		n->prev=NULL;
	}
}
void insend()
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	printf("\nENTER DATA: ");
	scanf("%d",&n->d);
	if(head==NULL)
	{
		head=n;
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{
		struct node *p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=n;
		n->prev=p;
		n->next=NULL;
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
		head->prev=n;
		head=n;
		n->prev=NULL;
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
		n->prev=p;
	}
}
void delbeg()
{
	if(head==NULL)
		printf("\nUNDERFLOW");
	else if(head->next==NULL)
	{
		struct node *dt=head;
		printf("\n%d has been deleted",dt->d);
		free(dt);
		head=NULL;
	}
	else
	{
		struct node *dt=head;
		printf("\n%d has been deleted",dt->d);
		head=head->next;
		free(dt);
		head->prev=NULL;
	}
}
void delend()
{
	if(head==NULL)
		printf("\nUNDERFLOW");
	else if(head->next==NULL)
	{
		struct node *dt=head;
		printf("\n%d has been deleted",dt->d);
		free(dt);
		head=NULL;
	}
	else
	{
		struct node *dt=head;
		while(dt->next!=NULL)
			dt=dt->next;
		printf("\n%d has been deleted",dt->d);
		dt->prev->next=NULL;
		free(dt);
	}
}
void delpos()
{
	int pos;
	printf("\nEnter the position to delete: ");
	scanf("%d",&pos);
	if(pos<0||pos>=getnode())
	{
		printf("\n---INVALID POSITION---");
	}
	else if(pos==0)
	{
		struct node *dt=head;
		printf("\n%d has been deleted",dt->d);
		head=head->next;
		head->prev=NULL;
		free(dt);
	}
	else
	{
		struct node *p=head;
		for(int i=1;i<pos;i++)
			p=p->next;
		struct node *dt=p->next;
		printf("\n%d has been deleted",dt->d);
		p->next=dt->next;
		dt->prev=p;
		p->prev=NULL;
		free(dt);
	}
}
void fdisp()
{
	if(head==NULL)
		printf("\n---DOUBLY LL EMPTY---");
	else
	{
		printf("\n---FORWARD---\n");
		printf("N");
		struct node *p=head;
		while(p!=NULL)
		{
			printf("<--> %d ",p->d);
			p=p->next;
		}
		printf("<--> N");
	}
}
void rdisp()
{
	if(head==NULL)
		printf("\n---DOUBLY LL EMPTY---");
	else
	{
		printf("\n---BACKWARD---\n");
		printf("N");
		struct node *p=head;
		while(p->next!=NULL)
			p=p->next;
		while(p!=NULL)
		{
			printf("<--> %d ",p->d);
			p=p->prev;
		}
		printf("<-->N");
	}
}
int main()
{
	printf("\n1. Insert at begining\n2. Insert at ending\n3. Delete from beginning\n4. Delete from ending\n5. Forward display\n6. Backward display\n7.Insert at position\n8.Delete from Position\n0. Exit");
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
			delbeg();
		else if (ch==4)
			delend();
		else if (ch==5)
			fdisp();
		else if(ch==6)
			rdisp();
		else if(ch==7)
			inspos();
		else if(ch==8)
			delpos();
		else if (ch==0)
			break;
		else
			printf("\nINVALID");
	}
}

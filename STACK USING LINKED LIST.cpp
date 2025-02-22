//STACK USING LINKED LIST
#include<stdio.h>
#include<malloc.h>
struct node{
	int d;
	struct node *next;
};
struct node *head=NULL;
void push()
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter Data: ");
	scanf("%d",&n->d);
	if(head==NULL)
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
void pop()
{
	if (head==NULL)
		printf("\nUNDERFLOW STACK");
	else
	{
		struct node *dt=head;
		head=head->next;
		printf("\n%d has been deleted from the stack",dt->d);
		free(dt);
	}
}
void disp()
{
	if (head==NULL)
		printf("\nSTACK EMPTY");
	else
	{
		struct node *p=head;
		while(p!=NULL)
		{
			printf("%d\n",p->d);
			p=p->next;
		}
	}
}
int main()
{
	printf("\n1.INSERT STACK\n2.DELETE STACK\n3.DISPLAY STACK\n0.EXIT");
	while(1)
	{
		int ch;
		printf("\nENTER CHOICE: ");
		scanf("%d",&ch);
		if(ch==1)
			push();
		else if(ch==2)
			pop();
		else if(ch==3)
			disp();
		else if(ch==0)
		{
			printf("\nEXITING THE PROGRAM!! GOODBYE!!");
			break;
		}	
		else
			printf("\n---INVALID CHOICE---");
	}
}

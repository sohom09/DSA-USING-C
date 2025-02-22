//QUEUE USING LINKED LIST
#include<stdio.h>
#include<malloc.h>
struct node{
	int d;
	struct node *next;
};
struct node *head=NULL;
void enqueue()
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
		struct node *p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=n;
		n->next=NULL;
	}
}
void dequeue()
{
	if (head==NULL)
		printf("\nUNDERFLOW QUEUE");
	else
	{
		struct node *dt=head;
		head=head->next;
		printf("%d has been deleted from the queue",dt->d);
		free(dt);
	}
}
void disp()
{
	if (head==NULL)
		printf("\nQUEUE EMPTY");
	else
	{
		struct node *t=head;
		while(t!=NULL)
		{
			printf("%d\t",t->d);
			t=t->next;
		}
	}
}
int main()
{
	printf("\n1.INSERT QUEUE\n2.DELETE QUEUE\n3.DISPLAY QUEUE\n0.EXIT");
	while(1)
	{
		int ch;
		printf("\nENTER CHOICE: ");
		scanf("%d",&ch);
		if(ch==1)
			enqueue();
		else if(ch==2)
			dequeue();
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


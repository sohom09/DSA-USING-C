#include<stdio.h>
#include<malloc.h>
#define size 10
struct node{
	int d;
	struct node *next;
};
struct node *ht[size];
int hash(int d)
{
	return d%10;
}
void insert()
{
	struct node *n=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data:");
	scanf("%d",&n->d);
	int htag=hash(n->d); //get hashtag
	if (ht[htag]==NULL)
	{
		ht[htag]=n;
		ht[htag]->next=NULL;
	}
	else
	{
		struct node *p=ht[htag];
		while(p->next!=NULL)
			p=p->next;
		p->next=n;
		n->next=NULL;
	}
}
void getid()
{
	int x;
	printf("\nEnter search data:");
	scanf("%d",&x);
	struct node *p=ht[hash(x)];
	int pos=0;
	while(p!=NULL)
	{
		if (p->d==x)
			break;
		else
		{
			p=p->next;
			pos++;
		}
	}
	if (p==NULL)
		printf("\nNot Found in Hashtable");
	else
		printf("\nHash: %d\n Position: %d",hash(x),pos);
}
void disp()
{
	for (int i=0;i<size;i++)
	{
		printf("\n#%d ",i);
		struct node *head=ht[i];
		if (head==NULL)
			printf("null ");
		else
		{
			struct node *p=head;
			while(p!=NULL)
			{
				printf("%d -> ",p->d);
				p=p->next;
			}
			printf("null");
		}
	}
}
void del()
{
	int x;
	printf("\nEnter DELETE data:");
	scanf("%d",&x);
	if (ht[hash(x)]->d==x)
	{
		struct node *del=ht[hash(x)];
		ht[hash(x)]=ht[hash(x)]->next;
		printf("%d has been deleted",x);
		free(del);
	}
	else
	{
		struct node *pre=ht[hash(x)];
		struct node *p=ht[hash(x)]->next;
		while(p!=NULL)
		{
			if (p->d==x)
				break;
			else
			{
				p=p->next;
				pre=pre->next;
			}
		}
		printf("%d has been deleted",x);
		pre->next=p->next;
		free(p);
	}
}
void init()
{
	for (int i=0;i<size;i++)
		ht[i]=NULL;
}
int main()
{
	init();
	printf("\n1. Insert\n2. Delete\n3. Display\n4. GetID\n0. Exit");
	while (1)
	{
		int ch;
		printf("\nEnter choice:");
		scanf("%d",&ch);
		if (ch==1)
			insert();
		else if (ch==2)
			del();    
		else if (ch==3)
			disp();
		else if (ch==4)
			getid();
		else if (ch==0)
			break;
		else
			printf("\nINVALID");
	}
}

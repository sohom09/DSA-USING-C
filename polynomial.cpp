#include<stdio.h>
#include<malloc.h>
struct pol{
	int coef;
	int expo;
	struct pol *next;
};
struct pol* create(struct pol *p)
{
	printf("\n1. Enter value\n2. Confirm");
	struct pol *x=p, *pre;
	while(1)
	{
		int ch;
		printf("\nEnter choice:");
		scanf("%d",&ch);
		if (ch==1)
		{
			int c,e,f=0;
			printf("\nEnter coef and expo:");
			scanf("%d%d",&c,&e);
			if (x==NULL)
			{
				struct pol *n=(struct pol*)malloc(sizeof(struct pol));
				n->coef=c,n->expo=e;
				x=n;
				x->next=NULL;
			}
			else
			{
				struct pol *pn=x;
				while(pn!=NULL) // 3x^3 - 2x + 9 + x^2
				{
					if (pn->expo == e)
					{
						f=1;
						break;
					}
					else
					{
						pre=pn;
						pn=pn->next;
					}		
				}
				if (f==1)
					pn->coef+=c;
				else
				{
					struct pol *n=(struct pol*)malloc(sizeof(struct pol));
					n->coef=c, n->expo=e;
					pre->next=n;
					n->next=NULL;
				}
			}	
		}
		else if (ch==2)
			break;
		else
			printf("\nINVALID");
	}
	return x;
}
void disp(struct pol *p)
{
	if (p==NULL)
		printf("\nNo polynomial found");
	else
	{
		struct pol *x=p;
		while(x!=NULL)
		{
			if (x->expo>1 || x->expo<0)
			{
				if (x->coef>0)
					printf("+ %dx^%d ",x->coef,x->expo);
				else
					printf("%dx^%d ",x->coef,x->expo);
			}
				
			else if (x->expo>0)
			{
				if (x->coef>0)
					printf("+ %dx ",x->coef);
				else
					printf("%dx ",x->coef);
			}
			else
			{
				if (x->coef>0)
					printf("+ %d ",x->coef);
				else
					printf("%d ",x->coef);
			}
			x=x->next;
		}
	} 
}
int main()
{
	struct pol *p1=NULL,*p2=NULL;
	p1=create(p1);
	disp(p1);
	p2=create(p2);
	disp(p2);
}

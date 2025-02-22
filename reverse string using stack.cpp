#include<stdio.h>
#define size 20
char st[size],rst[size];
int topst=-1,toprst=-1;
char pop()
{
	if(topst==-1)
		return '\0';
	else
		return st[topst--];
}
void push(char x )
{
	if(toprst==size-1)
		return;
	else
		rst[++toprst]=x;
		
}
int main()
{
	printf("\nENTER STRING: ");
	gets(st);
	int len;
	for(len=0;st[len]!='\0';len++);
	topst=len-1;
	for(int i=0;i<len;i++)
		push(pop());
	rst[len]='\0';
	printf("\nREVERSED STRING: %s ",rst);
}

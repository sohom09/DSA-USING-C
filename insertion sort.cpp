#include<stdio.h>
int main() //insertion
{
	int ar[]={4,3,1,5,2,9,6,11,7};
	int ln=sizeof(ar)/sizeof(ar[0]);
	for (int i=0;i<ln-1;i++)
	{
		if (ar[i+1]<ar[i])
		{
			int t=ar[i];
			ar[i]=ar[i+1];
			ar[i+1]=t;
			i=-1;
		}
	}
	for (int i=0;i<ln;i++)
			printf("%d\t",ar[i]);
}

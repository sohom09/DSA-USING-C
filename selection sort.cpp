#include<stdio.h>
int main() //selection
{
	int ar[]={4,3,2,5,1}; 
	int ln=sizeof(ar)/sizeof(ar[0]);
	for (int i=0;i<ln;i++)
	{
		int min=ar[i],minind=i;
		for (int j=i;j<ln;j++) 
		{
			if (ar[j]<min)
			{
				min=ar[j];
				minind=j;
			}
		}
		int t=ar[i];
		ar[i]=ar[minind];
		ar[minind]=t;
	}
	for (int i=0;i<ln;i++)
			printf("%d\t",ar[i]);
}

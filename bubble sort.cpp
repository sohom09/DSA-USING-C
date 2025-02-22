#include<iostream>
using namespace std;
class bubble{
	private:
		int ar[10],i,j,temp=0;
	public:
		void input();
		void sort();
		void selection();
};
void bubble::input()
{
	cout<<"Enter 10 elements into the array: "<<endl;
	for(i=0;i<10;i++)
	{
		cin>>ar[i];
	}
	cout<<"YOUR ARRAY: "<<endl<<endl;
	for(i=0;i<10;i++)
	{
		cout<<ar[i]<<"\t";
	}
}
void bubble::sort()
{
	for(i=0;i<10;i++)
	{
		for(j=i;j<10;j++)
		{
			if(ar[i]>ar[j])
			{
				temp=ar[i];
				ar[i]=ar[j];
				ar[j]=temp;
			}
			
		}
	}
	cout<<"\n\nYOUR SORTED ARRAY: "<<endl<<endl;
	for(i=0;i<10;i++)
	{
		cout<<ar[i]<<"\t";
	}
}
int main()
{
	bubble prog1;
	prog1.input();
	cout<<"\n\nAFTER BUBBLE SORT: "<<endl;
	prog1.sort();
	return 0;
}


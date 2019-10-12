#include<iostream>
#include<conio.h>
#include"SLL.h"
using namespace std;
template <class N>
void menu(SLL<N> &L)
{
	int n;
	char ch;
	N x;
	cout<<"Select SLL operation"<<endl;
	cout<<"1.Insert"<<endl;
	cout<<"2.Reverse SLL"<<endl;
	cout<<"3.Display"<<endl;
	cout<<"4.Delete"<<endl;
	cout<<"5.Search value by index"<<endl;
	cout<<"6.Search index by value"<<endl;
	cout<<"7.Display alternate elements"<<endl;
	cout<<"8.Display options"<<endl;
	do 
	{
		switch (getch()-48)
		{
			case 1:
			{
				cout<<"1=Beginning -1=End Else any position: ";
				cin>>n;
				cout<<"Enter data: ";
				cin>>x;
				L.insert(n,x);
				L.display();
				break;
				L.display();
			}
			case 2:
			{
				L.reverse();
				L.display();
				break;
			}
			case 3:
			{
				L.display();
				break;
			}
			case 4:
			{
				cout<<"1=Beginning -1=End Else any position";
				cin>>n;
				L.del(n);
				L.display();
				break;
			}
			case 5:
			{
				cout<<"1=Beginning -1=End Else any position";
				cin>>n;
				if(n>L.length())
				{
					cout<<"Index not found"<<endl;
				}
				else
				{
					cout<<L.svbi(n)<<endl;
				}
				break;	
			}
			case 6:
			{
				cout<<"Enter value:";
				cin>>n;
				n=L.sibv(n);
				if(n>0)
				{
					cout<<"Value found at node: "<<n<<endl;
				}
				else if(n==0)
				{
					cout<<"List is empty"<<endl;
				}
				else
				{
					cout<<"Value not found"<<endl;
				}
				break;
			}
			case 7:
			{
				L.displayalt();
				break;
			}
			case 8:
			{
				cout<<"1.Insert"<<endl;
				cout<<"2.Reverse SLL"<<endl;
				cout<<"3.Display"<<endl;
				cout<<"4.Delete"<<endl;
				cout<<"5.Search"<<endl;
				cout<<"6.Display alternate elements"<<endl;
				cout<<"7.Display options"<<endl;
				break;
			}
			default:
			{
				cout<<"Invalid option"<<endl;
			}
		}
		cout<<"Enter y to continue else end \r";
		ch=(char)getch();
		cout<<"                                               \r"<<"\b";
	}
	while (ch=='y' or ch=='Y');
}
int main()
{
	SLL<int> a;
	a.insert(3,0);
	a.insert(5,1);
	a.display();
	getch();
	SLL<int> b = a;
	getch();
	b.insert(6,0);
	a.insert(5,0);
	a.del(1);
	a.display();
	b.display();
	getch();
}

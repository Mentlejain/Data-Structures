#include<iostream>
#include<conio.h>
#include "sort.h"
using namespace  std;
template <class atype>
class search
{
	public:
	void linear(atype,atype*,int l);
	void binary(atype, atype*,int l);
};
template <class atype>
void search<atype>::linear(atype val,atype *a,int l)
{
	bool found=false;
	for(int i=0;i<l;i++)
	{
		if(a[i]==val)
		{
			cout<<"Value found at index: "<<i<<endl;
			found=true;
		}
	}
	if(!found)
	{
		cout<<"Value not found"<<endl;
	}
}
template <class atype>
void search<atype>::binary(atype val,atype *a,int l)
{
	int start=0;
	int end=l-1;
	int mid=(start+end)/2;
	while(start!=end)
	{
		if(val<a[mid])
		{
			end=mid;
		}
		else if(val>a[mid])
		{
			start=mid;
		}
		else
		{
			cout<<"Value found at index: "<<mid<<endl;
			break;
		}
		mid=(start+end)/2;
	}
}
template <class atype>
void display(atype *a,int l)
{
	for(int i=0;i<l;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	char ch;
	int n,val;
	cout<<"Enter length of array: ";
	cin>>n;
	cout<<"Enter array elements: ";
	int L[n];
	for(int i=0;i<n;i++)
	{
		cin>>L[i];
	}
	search<int> S;
	cout<<"Enter value to search: ";
	cin>>val;
	cout<<"1. Linear Search"<<endl;
	cout<<"2. Binary Search"<<endl;
	switch (getch()-48)
	{
		case 1:
		{
			S.linear(val,L,n);
			display(L,n);
			break;
		}
		case 2:
		{
			cout<<"Sorting the array"<<endl;
			sort<int> srt;
			srt.insertion(L,n);
			cout<<"Sorted array"<<endl;
			display(L,n);
			S.binary(val,L,n);
			break;
		}
		default:
		{
			cout<<"Invalid option"<<endl;
		}
	}
}

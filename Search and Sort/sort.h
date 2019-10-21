#include<iostream>
#include<conio.h>
using namespace  std;
template <class atype>
class sort
{
	public:
	void bubble(atype*,int l);
	void insertion(atype*,int l);
	void selection(atype*,int l);
};
template <class atype>
void sort<atype>::insertion(atype *a,int l)
{
	atype t;
	int j;
	for(int i=1;i<l;i++)
	{
		t=a[i];
		j=i-1;
		while(t<a[j] and j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
	}
}
template <class atype>
void sort<atype>::bubble(atype *a,int l)
{
	atype t;
	for(int i=1;i<l;i++)
	{
		if(a[i]<a[i-1])
		{
			t=a[i];
			a[i]=a[i-1];
			a[i-1]=t;
		}
	}
}
template <class atype>
void sort<atype>::selection(atype *a,int l)
{
	atype min,t;
	for(int i=0;i<l-1;i++)
	{
		min=i;
		for(int j=i+1;j<l;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		t=a[i];
		a[i]=a[min];
		a[min]=t;
	}
}

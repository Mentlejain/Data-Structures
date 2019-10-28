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
	void quick(atype*,int low, int high);
	void display(atype*, int);
	int partition(atype*, int low, int high);
	atype* merge(atype*, atype*)
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
	int min;
	atype t;
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
template <class atype>
void sort<atype>::quick(atype* p, int low, int high)
{
	if(low<high)
	{
		int i = partition(p, low, high);
		quick(p,low,i-1);
		quick(p,i+1,high);
	}
}
template <class atype>
int sort<atype>::partition(atype* p, int low, int high)
{
	atype temp;
	atype pivit = p[low];
	int j = low;
	for(int i=low+1; i<=high; i++)
	{	
		
		if(p[i]<=pivit)
		{
			j++;
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
		}
		
	}
	j;
	temp = p[low];
	p[low] = p[j];
	p[j] = temp;

	return j;
}
template <class atype>
void sort<atype>::display(atype *a,int l)
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
	int n;
	cout<<"Enter length of array: ";
	cin>>n;
	cout<<"Enter array elements: ";
	int L[n];
	for(int i=0;i<n;i++)
	{
		cin>>L[i];
	}
	sort<int> S;
	cout<<"1. Bubble Sort"<<endl;
	cout<<"2. Insertion Sort"<<endl;
	cout<<"3. Selection Sort"<<endl;
	cout<<"4. Quick Sort"<<endl;
	switch (getch()-48)
	{
		case 1:
		{
			S.bubble(L,n);
			S.display(L,n);
			break;
		}
		case 2:
		{
			S.insertion(L,n);
			S.display(L,n);
			break;
		}
		case 3:
		{
			S.selection(L,n);
			S.display(L,n);
			break;
		}
		case 4:
		{
			S.quick(L,0,n-1);
			S.display(L,n);
			break;
		}
		default:
		{
			cout<<"Invalid option"<<endl;
		}
	}
	getch();
}

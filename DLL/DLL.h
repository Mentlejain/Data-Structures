#include<iostream>
#include<conio.h>
using namespace std;
template <class N>
struct node
{
	N info;
	node *next=NULL;
	node *prev=NULL;
};
template <class N>
class DLL
{
	private:
		int l;
		node<N>* head=NULL;
		node<N>* prev=NULL;
	public:
		DLL();
		node<N>* headptr();
		bool isempty();//
		int length();//
		void insert(int val, N info);//
		void display();//
		void reverse();//
		void del(int);//
		N svbi(int);//
		int sibv(N);//
		void displayalt();//
		DLL operator+(DLL &L);
};
template <class N>
node<N>* DLL<N>::headptr()
{
	return head;
}
template <class N>
DLL<N>::DLL()
{
	l=0;
	head=NULL;}
template <class N>
bool DLL<N>::isempty()
{
	if (head==NULL)
		return true;
	else
		return false;
}
template <class N>
int DLL<N>::length()
{
	return l;
}
template <class N>
void DLL<N>::insert(int pos,N inf)
{
	node<N> *n=new node<N>;
	n->info=inf;
	n->next=NULL;
	n->prev=NULL;
	if(pos==1)
	{
		if(head==NULL)
		{
			head=n;
			l++;
			n=NULL;
			delete n;
		}
		else
		{
			n->next=head;
			head=n;
			n=NULL;
			delete n;
			l++;
		}
	}
	else if(pos==-1 or pos>l)
	{
		if(head==NULL)
		{
			head=n;
			head->next=NULL;
			l++;
			n=NULL;
			delete n;
		}
		else
		{
			node<N>* p;
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=n;
			n->prev=p;
			n->next=NULL;
			p=NULL;
			delete p;
			l++;
		}
	}
	else if(pos<=l)
	{
		node<N>* p;
		p=head;
		for(int i=1;i<pos-1 and p->next!=NULL;i++)
		{
			p=p->next;
		}
		n->next=p->next;
		n->prev=p;
		p->next=n;
		p=NULL;
		delete p;
		l++;
	}
}
template <class N>
void DLL<N> :: display()
{
	node<N>* p=new node<N>;
	p=head;
	cout<<"|<-";
	while(p!=NULL)
	{
		cout<<"["<<p->info<<"]"<<"<->";
		p=p->next;
	}
	cout<<"|"<<endl;
}
template <class N>
void DLL<N> ::displayalt()
{
	node<N>* p=new node<N>;
	p=head;
	while(true)
	{
		cout<<"["<<p->info<<"] ";
		if(p->next==NULL or p->next->next==NULL)
			break;
		p=p->next->next;
	}
	cout<<endl;
}
template <class N>
void DLL<N>::del(int pos)
{
	if(isempty())
		cout<<"List is empty"<<endl;
	else
	{
		if(pos==1)
		{
			node<N>* p;
			p=head;
			head=head->next;
			head->prev=NULL;
			p->next=NULL;
			p=NULL;
			delete p;
		}
		else if(pos==-1)
		{
			node<N>* p=new node<int>;
			node<N>* t=new node<int>;
			p=head;
			while(p->next!=NULL)
			{
				t=p;
				p=p->next;
			}
			t->next=NULL;
			p=t=NULL;
			delete p;
			delete t;
		}
		else
		{
			node<N>* p=new node<N>;
			node<N>* t=new node<N>;
			p=head;
			for(int i=1;i<pos and p->next!=NULL;i++)
			{
				t=p;
				p=p->next;
			}
			p->next->prev=t;
			t->next=p->next;
			p->next=NULL;
			p->prev=NULL;
			p=t=NULL;
			delete p;
			delete t;
		}
	}
}
template <class N>
void DLL<N>::reverse()
{
	if(isempty())
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		node<N>* p=NULL;
		while(true)
		{
			p=head->prev;
			head->prev=head->next;
			head->next=p;
			if(head->prev==NULL and p!=NULL)
			{
				break;
			}
			head=head->prev;
		}
	p=NULL;
	delete p;
	}
}
template <class N>
int DLL<N>::sibv(N val)
{
	if(isempty())
	{
		return -1;
	}
	else
	{
		int ind=0;
		node<N>* p;
		p=head;
		while(p!=NULL)
		{
			if(p->info==val)
			{
				return ind;
			}
			else
			{
				ind++;
			}
			p=p->next;
		}
		return 0;
	}
}
template <class N>
N DLL<N>::svbi(int pos)
{
	if(isempty())
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		N val;
		if(pos==1)
		{
			val=head->info;
			return val;
		}
		else if(pos==-1 or pos>l)
		{
			node<N>* p;
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			val=p->info;
			delete p;
			return val;
		}
		else if(pos<=l)
		{
			N val;
			node<N>* p;
			p=head;
			for(int i=1;i<pos and p->next!=NULL;i++)
			{
				p=p->next;
			}
			val=p->info;
			delete p;
			return val;
		}
	}
}
template <class N>
DLL<N> DLL<N>:: operator+ (DLL<N> &L)
{
	DLL<int>res;
	node<N>*p;
	p=head;
	while(p!=NULL)
	{
		res.insert(-1,p->info);
		p=p->next;
	}
	p=L.headptr();
	while(p!=NULL)
	{
		res.insert(-1,p->info);
		p=p->next;
	}
	delete p;
	return res; 	
}

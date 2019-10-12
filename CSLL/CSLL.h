#include<iostream>
#include<conio.h>
using namespace std;
template <class N>
struct node
{
	N info;
	node *next=NULL;
};
template <class N>
class CSLL
{
	private:
		int l;
		node<N>* tail=NULL;
	public:
		node<N>* tailptr();
	//	~CSLL();
		CSLL();//
		CSLL(CSLL &ob);//
		bool isempty(); //
		void reverse();//
		int length();//
		void insert(int val, N info);//
		void display();//
		void del(int);//
		N svbi(int);
		int sibv(N);
		void displayalt();//
		CSLL operator+(CSLL &L);
};
template <class N>
CSLL<N>::CSLL()
{
	tail=NULL;
	l=0;
}
template <class N>
node<N>* CSLL<N>::tailptr()
{
	return tail;
}
template <class N>
int CSLL<N>::length()
{
	return l;
}
template <class N>
bool CSLL<N>::isempty()
{
	if(tail==NULL)
		return true;
	else
		return false;
}
template <class N>
int CSLL<N>::sibv(N val)
{
	if(isempty())
	{
	//	cout<<"List is empty"<<endl;
		return 0;
	}
	else
	{
		int ind=0;
		node<N>* p;
		p=tail;
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
		}
		return -1;
	}
}
template <class N>
N CSLL<N>::svbi(int pos)
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
			val=tail->next->info;
			return val;
		}
		else if(pos==-1 or pos>l)
		{
			node<N>* p;
			p=tail->next;
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
			p=tail->next;
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
void CSLL<N>::insert(int pos,N inf)
{
	node<N> *n=new node<N>;
	n->info=inf;
	n->next=NULL;
	if(pos==1)
	{
		if(tail==NULL)
		{
			tail=n;
			tail->next=tail;
			l++;
			n=NULL;
			delete n;
		}
		else
		{
			
			n->next=tail->next;
			tail->next=n;
			n=NULL;
			delete n;
			l++;
		}
	}
	else if(pos==-1 or pos>l)
	{
		if(tail==NULL)
		{
			tail=n;
			tail->next=tail;
			l++;
			n=NULL;
			delete n;
		}
		else
		{
			n->next=tail->next;
			tail->next=n;
			tail=tail->next;
			l++;
		}
	}
	else if(pos<=l)
	{
		node<N>* p;
		p=tail->next;
		for(int i=1;i<pos-1 and p!=tail;i++)
		{
			p=p->next;
		}
		n->next=p->next;
		p->next=n;
		p=NULL;
		delete p;
		l++;
	}
}
template <class N>
void CSLL<N>::del(int pos)
{
	if(isempty())
		cout<<"List is empty"<<endl;
	else if(tail->next==tail)
	{
		tail->next=NULL;
		tail==NULL;
		l--;
	}
	else
	{
		if(pos==1)
		{
			node<N>* p;
			p=tail->next;
			tail->next=p->next;
			p->next=NULL;
			p=NULL;
			delete p;
			l--;;
		}
		else if(pos==-1)
		{
			node<N>* p=new node<int>;
			p=tail->next;
			while(p->next!=tail)
			{
				p=p->next;
			}
			p->next=tail->next;
			tail->next=NULL;
			tail=p;
			p=NULL;
			delete p;
			l--;
		}
		else
		{
			node<N>* p=new node<N>;
			node<N>* t=new node<N>;
			p=tail->next;
			for(int i=1;i<pos and p!=tail;i++)
			{
				t=p;
				p=p->next;
			}
			t->next=p->next;
			p->next=NULL;
			p=t=NULL;
			delete p;
			delete t;
			l--;
		}
	}
}
template <class N>
void CSLL<N> ::display()
{
	node<N>* p=new node<N>;
	p=tail->next;
	do
	{
		cout<<"["<<p->info<<"]"<<"->";
		p=p->next;
	}while(p!=tail->next);
	cout<<endl;
}
template <class N>
void CSLL<N>::reverse()
{
	if(isempty())
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		node<N>* n;
		node<N>* p;
		node<N>* c;
		p=tail->next;
		c=p->next;
		tail=tail->next;
		do
		{
			n=c->next;
			c->next=p;
			p=c;
			c=n;
		}while(p!=tail);
	}
}
template <class N>
void CSLL<N> ::displayalt()
{
	node<N>* p=new node<N>;
	p=tail->next;
	do
	{	
		cout<<"["<<p->info<<"] ";
		p=p->next->next;
	}
	while(p!=tail and p->next!=tail);
	cout<<endl;
}
template <class N>
CSLL<N> CSLL<N>:: operator+ (CSLL<N> &L)
{
	CSLL<int>res;
	node<N>*p;
	p=tail->next;
	do
	{
		res.insert(-1,p->info);
		p=p->next;
	}while(p!=tail);
	p=L.tailptr()->next;
	do
	{
		res.insert(-1,p->info);
		p=p->next;
	}while(p!=L.tailptr());
	p->next=tail->next;
	p=NULL;
	delete p;
	return res; 	
}

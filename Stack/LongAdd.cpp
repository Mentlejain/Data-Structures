#include<iostream>
#include<conio.h>
#include "StackTemplate.h"
#include<string>
#define add \
{\
carry=temp/10;temp=temp%10;\
sum=(char)(temp+48)+sum;\
}

using namespace std;
string LongAdd(string n1,string n2)
{
	int carry=0;
	int temp;
	string sum="";
	stack<int> s1(n1.length());
	stack<int> s2(n2.length());
	for(int i=0;i<n1.length();i++)
	{
		s1.push(((int) n1[i])-48);
	}
	for(int i=0;i<n2.length();i++)
	{
		s2.push(((int) n2[i])-48);
	}
	while(!s1.isempty() and !s2.isempty())
	{
		temp=s1.pop()+s2.pop()+carry;
/*		carry=temp/10;
		temp=temp%10;
		sum=(char)(temp+48)+sum;
*/		add;
	}
	while (s1.isempty() and !s2.isempty())
	{
		temp=s2.pop()+carry;
/*		carry=temp/10;
		temp=temp%10;
		sum=(char)(temp)+sum;
*/		add;
	}
	while(!s1.isempty() and s2.isempty())
	{
		temp=s1.pop()+carry;
/*		carry=temp/10;
		temp=temp%10;
		sum=(char)(temp)+sum;
*/		add;
	}
	if (carry==1)
	{
		sum=(char)(carry+48)+sum;
	}
	return sum;
}
int main()
{
	char ch=48;
	cout<<ch;
	string n1,n2;
	cout<<"Enter first number: ";
	getline(cin,n1);
	cout<<"Enter second number: ";
	getline(cin,n2);
	string sum=LongAdd(n1,n2);
	cout<<"Sum is :"<<sum<<endl;
	getch();
	
}

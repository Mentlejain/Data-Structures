#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include <math.h>
#include "StackTemplate.h"
#include<string>
using namespace std;
double postfix(string str)
{
	stack<double> s(str.length());
	double val1,val2;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]==' ' or str[i]=='\t')
		{
			continue;
		}
		if(isdigit(str[i]))
		{
			s.push((double)(str[i]-48));
		}
		else
		{
			val2=s.pop();
			val1=s.pop();
			switch(str[i])
			{
				case '+':
					s.push((val1+val2));
					break;
				case '-':
					s.push((val1-val2));
					break;
				case '*':
					s.push((val1*val2));
					break;
				case '/':
					s.push((val1/val2));
					break;
				case '^':
					s.push(pow(val1,val2));
					break;
			}
		}
	}
	return s.pop(); 
}
int main()
{
	string s;
	cout<<"Postfix Expression: ";
	getline(cin,s);
	cout<<"Evaluation: "<<postfix(s);
	getch();
}

#include<iostream>
using namespace std;
#include<stdio.h>
#include<limits>
#include<string.h>
#include<ctype.h>
#define SIZE 50
class Stack
{
	int top;
	char s[SIZE];
	char s1[20][SIZE];// 20 is no. of strings and size is max length of string

	public:
		Stack()
		{
			top=-1;
		}

		int isempty()
		{
			return top==-1;
		}

		int isfull()
		{
			return top==SIZE-1;
		}

		void push(char c)
		{
			if(!isfull())
			s[++top]=c;

			else
			cout<<"\n STACK OVERFLOW!";
		}
		void push(char e[])
		{
			if(!isfull())
			  strcpy(s1[++top],e);

			else
				cout<<"\n stack overflow!";
		}
		char pop()
		{
			if(!isempty())
			return s[top--];
			else
			cout<<"\n STACK UNDERFLOW!";
		}
		char* pop1()
		{
			if(!isempty())
			return s1[top--];
		}

		char gettop()
		{
			return s[top];
		}


	};
		int priority(char ch)
		{
			switch(ch)
			{
				case '^':
					return 3;

				case '*':
				case '/':
				case '%':
					return 2;

				case '+':
				case '-':
					return 1;

				case '(':
					return 0;
			}
		}
		void infix2postfix(char e[],int t)
		{
			char postfix[50];

			Stack s1;
			int i=0,j=0;
			while(e[i])
			{
				if(e[i]=='(' || e[i]=='*' || e[i]=='/' || e[i]=='+' || e[i]=='-' || e[i]=='^' || e[i]==')')
				{
						if(e[i]=='(')
						  s1.push('(');

						else if(e[i]==')')
						{
							while(s1.gettop()!='(')
							{
								postfix[j++]=s1.pop();
							}
							s1.pop();
						}

						else
						{
								if(s1.isempty())
								s1.push(e[i]);

								else
								{
									if(t==0)
									{
										while(!s1.isempty() && priority(e[i])<=priority(s1.gettop()))
										postfix[j++]=s1.pop();
										s1.push(e[i]);
									}
									else
									{
										while(!s1.isempty() && priority(e[i])<priority(s1.gettop()))
										postfix[j++]=s1.pop();
										s1.push(e[i]);
									}
								}
						}
				}
				else
				{
					postfix[j++]=e[i];
				}
				i++;
			}

				while(!s1.isempty())
				{
					postfix[j++]=s1.pop();
				}
			   postfix[j]=0;
			   int len;
			   if(t==0)
				cout<<"\n POSTFIX:"<<postfix;
			   else
			   {
				  len=strlen(postfix);
				  while(len--)
				  {
					cout<<postfix[len];
				  }
			   }
		}

		void infix2prefix(char e[],int i)
		{
			int j=0;
			char a[50];
			while(i--)
			{
				if(e[i]=='(')
					a[j]=')';

				else if(e[i]==')')
					a[j]='(';
				else
					a[j]=e[i];

				j++;
			}
			a[j]='\0';
			infix2postfix(a,1);
		}
		void postfix2infix(char e[],int k)
		{
			int i=0;
			char temp[50]={0};
			char conc[2]={0};
			char op1[50],op2[50];
			Stack s1;
			while(e[i])
			{
				if(isalpha(e[i]))
				{
				   temp[0]=e[i];
				   temp[1]='\0';
				   s1.push(temp);
				}
				else
				{
				  if(k==0)
				  {
					 strcpy(op2,s1.pop1());
					 strcpy(op1,s1.pop1());
				  }
				  if(k==1)
				  {
					 strcpy(op1,s1.pop1());
					 strcpy(op2,s1.pop1());
				  }
				  conc[0]=e[i];
				  strcpy(temp+1,op1);
				  strcat(temp,conc);
				  strcat(temp,op2);
				  temp[0]='(';
				  int len;
				  len=strlen(temp);
				  temp[len]=')';
				  temp[len+1]='\0';
				  s1.push(temp);
				}
				i++;
			}
			cout<<"\n Infix expression:"<<s1.pop1();
		}
		void postfix2prefix(char e[])
		{
			Stack s1;
			int i=0;
			char temp[50]={0};
			char conc[2]={0};
			char op1[50],op2[50];

			while(e[i])
			{
				if(isalpha(e[i]))
				{
					temp[0]=e[i];
					temp[1]='\0';
					s1.push(temp);
				}
				else
				{
				  strcpy(op2,s1.pop1());
				  strcpy(op1,s1.pop1());
				  conc[0]=e[i];
				  strcpy(temp,conc);
				  strcat(temp,op1);
				  strcat(temp,op2);
				  int len;
				  len=strlen(temp);
				  temp[len+1]='\0';
				  s1.push(temp);
				}
				i++;
			}
			cout<<"\n Prefix expression:"<<s1.pop1();
		}
		void prefix2infix(char e[],int i)
		{
			char a[100];
			int j=0;
			while(i--)
			{
			  a[j]=e[i];
			  j++;
			}
			a[j]='\0';
			int k=1;
			postfix2infix(a,k);
		}
		void prefix2postfix(char e[],int i)
		{
			Stack s1;
			char temp[50]={0};
			char conc[2]={0};
			char op1[50],op2[50];

			while(i--)
			{
				if(isalpha(e[i]))
				{
					temp[0]=e[i];
					temp[1]='\0';
					s1.push(temp);
				}
				else
				{
				  strcpy(op1,s1.pop1());
				  strcpy(op2,s1.pop1());
				  conc[0]=e[i];
				  strcpy(temp,op1);
				  strcat(temp,op2);
				  strcat(temp,conc);
				  int len;
				  len=strlen(temp);
				  temp[len+1]='\0';
				  s1.push(temp);
				}
			}
			cout<<"\n Postfix expression:"<<s1.pop1();

		}
	int main()
	{
		char e[100];
		int ch;

		do
		{
			cout<<"\n =======================conversions========================\n";

			cout<<"\n enter choice:\n 1.Infix to Postfix \n 2.Infix to Prefix \n 3.Postfix to infix \n 4.Postfix to prefix \n 5.Prefix to infix \n 6.Prefix to postfix\n ";
			scanf("%d",&ch);
			cin.ignore(numeric_limits<streamsize>::max(),'\n');

			switch(ch)
			{
				case 1:
				{
					cout<<"\n INFIX TO POSTFIX:";
					cout<<"\n enter infix expression:";
					cin.getline(e,100);

					infix2postfix(e,0);
				}break;

				case 2:
				{

					cout<<"\n INFIX TO PRFIX:";
					cout<<"\n enter infix expression:";
					int i=0;
					cin.getline(e,100);
					i=strlen(e);
					infix2prefix(e,i);
				}break;

				case 3:
				{
					cout<<"\n POSTFIX TO INFIX:";
					cout<<"\n enter postfix expression:";
					cin.getline(e,100);
					int k=0;
					postfix2infix(e,k);
				}break;
				case 4:
				{
					cout<<"\n Postfix to prefix:";
					cout<<"\n enter postfix expression:";
					cin.getline(e,100);
					postfix2prefix(e);
				}break;

				case 5:
				{
					cout<<"\n Prefix to infix:";
					cout<<"\n enter prfix expression:";
					cin.getline(e,100);
					int i;
					i=strlen(e);
					prefix2infix(e,i);

				}break;

				case 6:
				{
					cout<<"\n PREFIX TO POSTFIX:";
					cout<<"\n enter prefix expression:";
					cin.getline(e,100);
					int i;
					i=strlen(e);
					prefix2postfix(e,i);
				}break;
			}
		}while(ch<7);
	return 0;
	}


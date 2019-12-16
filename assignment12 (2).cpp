#include<stdio.h>
#include<iostream>
#define max 30
using namespace std;

class pizza
{
	int price;
	
	public:
		pizza()
		{
			price=0;
		}
		void type(int ch)
		{
			switch(ch)
			{
				int k;
				case 1:
				{
					cout<<"\n enter the quantity:";
					cin>>k;
					price+=250*k;
				}
				break;		
				case 2:
				{
					cout<<"\n enter the quantity:";
					cin>>k;
					price+=350*k;
				}
				break;
				case 3:
				{
					cout<<"\n enter the quantity:";
					cin>>k;
					price+=450*k;
				}
				break;
			}
		}
		
		int price1()
		{
			return price;
		}
		
};
class queue
{
	int q[max];
	int rear;
	int front;
	int size;
	
		public:
			queue()
			{
				rear=-1;
				front=-1;
				size=0;
			}
	
		int isfull()
		{
			return size==max;
		}
		
		int isempty()                                                                   
		{
			return size==0;
   		}
   		
   		void add_pizza(int a)
   		{
   			if(!isfull())
   			{
   				if(rear==-1)
   				{	
   					++rear;
   					q[rear]=a;
   				}
   				else
   				{
   					rear=(rear+1)%30;
   					q[rear]=a;
   				}
   				size++;
   				cout<<"\n PIZZA ORDER NO. "<<a<<"added!";
   			}			
   			else
   				cout<<"\n PIZZA ORDERS ARE FULL(CURRENTLY UNAVAILABLE)";
   		}
	
		void servepizza()
		{
			if(!isempty())
			{
				++front;
				cout<<"\n order no."<<q[front]<<"served!";
				size--;
			}
			else
				cout<<"\n all orders are already served";
		}	
}; 	

int main()
{
	queue q1;
	pizza p1;
	int n,ch,on;
	char m;
	do
	{
		int g;
		cout<<"\n enter \n  1.  TO  PLACE ORDERS \n  2.  TO SERVE ORDER: ";
		cin>>g;
		switch(g)
		{
			case 1:
			{			
				cout<<"\n ****************************MENU CARD DOMINO'S****************************";
				cout<<"\n  PIZZA NAME:          COST(INR)";
				cout<<"\n  1. Margherita          RS. 250/   \n  2. Marinara            RS 350/  \n  3.Quattro Stagion      RS 450/ ";
				cout<<"\n enter the order no.";
				cin>>on;
				q1.add_pizza(on);
				char  f;
				do
				{
					cout<<"\n enter the pizza no. to be added:";
					cin>>ch;
					p1.type(ch);
					cout<<"\n do you want to add more pizza?: (y or n)";
					cin>>f;
				}while(f=='y' || f=='Y');
					cout<<"\n price of order no."<<on<<"="<<p1.price1();
					cout<<"\n  do you want to continue ?(y or n)";
					cin>>m;
			}
			break;
			
			case 2:
			{
				q1.servepizza();	
			}
			break;
		}
	}
	while(m=='y' || m=='Y');	
return 0;
}



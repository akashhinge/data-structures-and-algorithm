#include<iostream>
#define max 50
using namespace std;
class queue
{
	  private:
	  	int rear;
	  	int front;
	  	int q[max];	
	  	int i;
	  	
	  public:
	  	
	  	queue()
	  	{
	  		rear=-1;
	  		front=-1;
	  		i=-10;
	  	}
	  	
	  	int isfull()
	  	{
	  		return rear==max-1;
	  	}
	  	
	  	int isempty()
	  	{
	  		return front==rear;
	  	}
	
		void add_job(int a)
		{
			if(!isfull())
			{
				q[++rear]=a;
				cout<<"\n application no. " <<a<<" JOB ADDED !:";
			}
			else
			cout<<"\n NO VACANCY!";			
		}

		void del_job()
		{
			if(!isempty())
			{
				front++;
				cout<<"\n application no. "<<q[front]<<" JOB DELETED!";
			}	
			else
			{
				cout<<"\n ALL JOBS ARE ALREADY VACANT!(cant delete any job) ";
			}
		}
		
		int gettop()
		{
			++i;
			if(!isempty())
			return q[i];
		}
};

int main()
{
	queue q1;
	int n,i;
	int u=0;
	int a[50];
	cout<<"\n JOB SYSTEM:";
	do
	{
		cout<<"\n  ENTER  \n 1. to add job \n 2.delete a job \n 3.display all jobs";
		cout<<"\n enter the no. of applicants";
		cin>>i;
		switch(i)
		{
			case 1:
				{
					int a;
					cout<<"\n enter job application to be added:";
					cin>>a;
					q1.add_job(a);		
					u++;
				}
				break;
				
				case 2:
				{
					q1.del_job();
				}
				break;
				
				case 3:
				{
					cout<<"\n jobs available:";
					for(int i=0;i<u;i++)
					{
					 	int h;
						h=q1.gettop();
						cout<<"application no."<<h<<"\n";
					}
				}
				break;
		}
	}while(i<4);
	return 0;
}

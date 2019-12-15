/* Assignment 13 
	write a c++ program to store names and mobile numbers of your friends in sorted order on names. Search your friend from list using binary search (recursive and non-recursive).Insert friend if not present in the phone book*/

#include<iostream>
#include<iomanip>
using namespace std;

class friends
{
	string name;
	long mb;
	
	public:
		friends()
		{
		}
		
		friend class binsearch;
};

class binsearch
{
	friends *f;
	int n;
	
	public:
		binsearch()
		{
		
		}
		
		void addfriends(int no)
		{
			n=no;
			f=new friends[n];
			for(int i=0;i<n;i++)
			{
				cout<<"\n enter the name :";
				cin>>f[i].name;
			
				cout<<"\n enter the mob no.";
				cin>>f[i].mb;
			}	
		}
		
		void sort()
		{
			for(int i=0;i<n-1;i++)
			{
				int minindex=i;
				for(int j=i+1;j<n;j++)
				{
					if(f[j].name<f[minindex].name)
						minindex=j;
				}
				if(i!=minindex) //swap only when 
				{
					string tempname;
					tempname=f[i].name;
					f[i].name=f[minindex].name;
					f[minindex].name=tempname;
				
					long tempno;
					tempno=f[i].mb;
					f[i].mb=f[minindex].mb;
					f[minindex].mb=tempno;
				}
			}
		}
		
		void displaydatabase()
		{
			cout<<"\n Name"<<setw(20)<<"mobno"<<setw(20);
			for(int i=0;i<n;i++)
			{
				cout<<"\n "<<f[i].name<<setw(20)<<f[i].mb<<setw(20);
			}
		}
		
		void iterativesearch(string name1)
		{
			int i=0;
			int j=n-1;
			int mid;
			
			while(i<=j)
			{
				mid=(i+j)/2;
				if(f[mid].name==name1)
				{
					cout<<"\n FRIEND FOUND !";
					cout<<"\n NAME :"<<f[mid].name;
					cout<<"\n MOB. NO."<<f[mid].mb;
					return ;
				}
				
				else if(name1<f[mid].name)
				{
					j=mid-1;
				}

				else
				{
					i=mid+1;
				}			
			}
			
			cout<<"\n RECORD NOT FOUND ";
			char choice;
			cout<<"\n do you want to add the no. (y/n)";
			cin>>choice;
			
			if(choice=='y' || choice=='Y')
			{
				f[n].name=name1;
				cout<<"\n enter the mob no.";
				cin>>f[n].mb;
				n++;
			}		
			return;		
		}
		int getn()
		{
			return n;
		}
		void recursivesearch(int i,int j,string name2)
		{
			
			int mid=(i+j)/2;
			if(i>j)
			{
				cout<<"\n RECORD NOT FOUND ";
				char choice;
				cout<<"\n do you want to add the no. (y/n)";
				cin>>choice;
			
				if(choice=='y' || choice=='Y')
				{
					f[n].name=name2;
					cout<<"\n enter the mob no.";
					cin>>f[n].mb;
					n++;
				}		
				return;		
			}
		
			if(f[mid].name==name2)
			{
				cout<<"\n FRIEND FOUND !";
				cout<<"\n NAME :"<<f[mid].name;
				cout<<"\n MOB. NO."<<f[mid].mb;
				return ;
			}
		
			if(name2<f[mid].name)
				recursivesearch(i,mid-1,name2);
			
			if(name2>f[mid].name)
				recursivesearch(mid+1,j,name2);
		}
};

int main()
{
	binsearch b;
	int n,ch1;
	char ch2;
	string name1,name2;
	
	do
	{
		cout<<"\n enter the choice \n 1. add friends to list \n 2. search for a friend (non-recursive) \n 3. search for a friend (recursive) \n ";
		cin>>ch1;
		
		switch(ch1)
		{
			case 1:
			
				cout<<"\n enter the number of friends to be added ";
				cin>>n;
				b.addfriends(n);
				b.sort();
				b.displaydatabase();
				break;

			case 2:
				cout<<"\n enter the name of the friend to be searched ";
				cin>>name1;
				b.iterativesearch(name1);
				break;
				
			case 3:
				cout<<"\n enter the name of the friend to be searched ";
				cin>>name2;
				int n1=b.getn();
				b.recursivesearch(0,n1-1,name2);
				break;		
		}
		cout<<"\n do you want to continue(y/n)";
		cin>>ch2;
	}while(ch2=='y' || ch2=='Y');
	

return 0;
}
/*
akash@akash-HCL-ME-Laptop:~$ cd final
akash@akash-HCL-ME-Laptop:~/final$ g++ assignment13.cpp
akash@akash-HCL-ME-Laptop:~/final$ ./a.out

 enter the choice 
 1. add friends to list 
 2. search for a friend (non-recursive) 
 3. search for a friend (recursive) 
 1

 enter the number of friends to be added 4

 enter the name :akash

 enter the mob no.7620

 enter the name :amod

 enter the mob no.1111

 enter the name :ab

 enter the mob no.9999

 enter the name :roshan

 enter the mob no.4444

 Name               mobno                  
 ab                9999                  
 akash                7620                  
 amod                1111                  
 roshan                4444
 do you want to continue(y/n)y

 enter the choice 
 1. add friends to list 
 2. search for a friend (non-recursive) 
 3. search for a friend (recursive) 
 2

 enter the name of the friend to be searched roshan

 FRIEND FOUND !
 NAME :roshan
 MOB. NO.4444
 do you want to continue(y/n)y

 enter the choice 
 1. add friends to list 
 2. search for a friend (non-recursive) 
 3. search for a friend (recursive) 
 3

 enter the name of the friend to be searched ab

 FRIEND FOUND !
 NAME :ab
 MOB. NO.9999
 do you want to continue(y/n)y

 enter the choice 
 1. add friends to list 
 2. search for a friend (non-recursive) 
 3. search for a friend (recursive) 
 3

 enter the name of the friend to be searched tejas

 RECORD NOT FOUND 
 do you want to add the no. (y/n)n

 do you want to continue(y/n)n
akash@akash-HCL-ME-Laptop:~/final$ 
*/

/*	Assignment 14
write a c++ program to store first year percentage of students in array. write function of sorting array of floating point numbers in ascending numbers in ascending order using a) selection sort b)Bubble sort c)merge sort and display top five scores*/
#include<iostream>
#include<iomanip>
using namespace std;

class Array
{
	float *a;
	int size;
	
	public:
		Array(int s)
		{
			size=s;
			a=new float[size];
		}
		
		void input()
		{
			cout<<"\n Enter percentage of"<<size<<" students \n";
			for(int i=0;i<size;i++)
			{
				cin>>a[i];
			}
		}
		
		void display()
		{
			cout<<"\n";
			for(int i=0;i<size;i++)
			{
				cout<<a[i]<<"\t";
			}
		}
		
		void swap(float &x , float &y)
		{
			float temp;
			temp=x;
			x=y;
			y=temp;
		}
		
		void selectionsort()
		{
			cout<<"\n Selection sort \n";
			int minindex;
			
			for(int i=0;i<size-1;i++)
			{
				minindex=i;
				
				for(int j=i+1;j<size;j++)
				{
					if(a[j]<a[minindex])
						minindex=j;
				}
				swap(a[i],a[minindex]);
				display();
			}
		}
/*	In bubble sort greatest element is bubbled towards the last*/		
		void bubblesort()
		{
			for(int i=0;i<size-1;i++)
			{
				for(int j=0;j<size-1-i;j++)
				{
					if(a[j]>a[j+1])
					{
						swap(a[j],a[j+1]);
						display();
					}	
				}
			}
		}
		
		void merge(int low ,int mid, int high)
		{
			int lsize=mid-low+1;
			int rsize=high-(mid+1)+1;
			
			float *l=new float[lsize];
			float *r=new float[rsize];
		
			int i,j;
			
	
			for(i=low;i<=mid;i++)
			{
				l[i-low]=a[i];
			} 
			
			for(j=mid+1;j<=high;j++)
			{
				r[j-mid-1]=a[j];
			}
		
			i=low;
			j=mid+1;
			int i1=0;
			int j1=0;
			int k=low;
			
			while(i<=mid && j<=high)
			{
				if(l[i1]<r[j1])
				{
					a[k++]=l[i1++];
					i++;
				}
					
				else
				{				
					a[k++]=r[j1++];
					j++;
				}
			}
			
			while(i<=mid)
			{
				a[k++]=l[i1++];
				i++;
			}
			
			while(j<=high)
			{
				a[k++]=r[j1++];
				j++;
			}
		}
		
		void mergesort(int low , int high)
		{
			if(low<high)
			{
				mergesort(low,(low+high)/2);
				mergesort((low+high)/2+1,high);
				merge(low,(low+high)/2,high);
			}
		}
		
	/*merge sort works on divide and conquer strategy*/
};

int main()
{
	int n,ch1;
	char ch2;
	
	cout<<"\n enter the no. of students ";
	cin>>n;
	
	Array	a1(n);
	a1.input();
	do
	{
		cout<<"\n ENTER : \n 1. selection sort \n 2. bubble sort \n 3. merge sort \n";
		cin>>ch1;
		
		switch(ch1)
		{
			case 1:
				cout<<"\n Display before sort :";
				a1.display();
				cout<<"\n\n\n";
				a1.selectionsort();
				break;
				
			case 2:
				cout<<"\n Display before sort :";
				a1.display();
				cout<<"\n\n\n";
				a1.bubblesort();
				break;	
				
			case 3:
				cout<<"\n Display before sort :";
				a1.display();
				cout<<"\n\n\n";
				a1.mergesort(0,n-1);
				cout<<"\n after merge sort :";
				a1.display();
				break;					
		}
		
		cout<<"\n do you want to continue (y/n)";
		cin>>ch2;
	}while(ch2=='y' || ch2=='Y');	

return 0;
}

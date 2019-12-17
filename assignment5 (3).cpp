/*Assignment 5
Write C++ program for sparse matrix realization and operations on it- Transpose, Fast Transpose and addition of two matrices */
#include<iostream>
using namespace std;
class matrix
{
	protected:
	
		int rows;
		int columns;
		int **arr;
	
	public:
		matrix()
		{
		}
		matrix(int r,int c)
		{
			rows=r;
			columns=c;
			arr=new int*[rows];
			for(int i=0;i<rows;i++)
				arr[i]=new int[columns];
				
		}
};

class sparsematrix:public matrix 
{
	int nz=0;

	public:
		sparsematrix()
		{
		}
	
		sparsematrix(int r,int c):matrix(r,c)
		{
		}
		
		void getmatrix()
		{
			cout<<"\n enter "<<rows*columns<<"elements";
			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<columns;j++)
				{
					cin>>arr[i][j];
					if(arr[i][j])
						nz++;	
				}
			}
		}
		
		void convert()
		{
			int **temp;
			temp=new int* [nz];
			for(int i=0;i<nz+1;i++)
				temp[i]=new int[3];
				
			temp[0][0]=rows;
			temp[0][1]=columns;
			temp[0][2]=nz;
			
			int k=1;
			
			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<columns;j++)
				{
					if(arr[i][j])
					{
						temp[k][0]=i;
						temp[k][1]=j;
						temp[k][2]=arr[i][j];
						k++;
					}	
				}
			}
			
			arr=temp;
			rows=nz+1;
			columns=3;
		}
		
		void display()
		{
			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<columns;j++)
					cout<<arr[i][j]<<"\t";
					
				cout<<"\n";
			}
		}
		int search(int r, int c, sparsematrix &m2)
		{
				for(int j=1;j<=m2.arr[0][2];j++)
				{
					if(m2.arr[j][0]==r && m2.arr[j][1]==c)
						return 1;	
				}
				return 0;
		}
		sparsematrix operator+(sparsematrix &m2)
		{
		
				int r=arr[0][2]+m2.arr[0][2];
				for(int i=1;i<=arr[0][2];i++)
				if(search(arr[i][0],arr[i][1],m2)) 
					r--;
					
				sparsematrix temp(100,100);		// object of sparse matrix	
				temp.arr[0][0]=arr[0][0];
				temp.arr[0][1]=arr[0][1];
				temp.arr[0][2]=r;
				
				int i=1,j=1,k=1;
				cout<<"hello";
				
				while(i<=arr[0][2] && j<=arr[0][2])
				{
					if(arr[i][0]==m2.arr[i][0])
					{
						if(arr[i][1]==m2.arr[j][0])
						{
							temp.arr[k][0]=arr[i][0];
							temp.arr[k][1]=arr[i][1];
							temp.arr[k][2]=arr[i][2]+m2.arr[j][2];
							i++;
							j++;
							k++;
						}
						
						else if(arr[i][1]<m2.arr[j][1])
						{
							temp.arr[k][0]=arr[i][0];
							temp.arr[k][1]=arr[i][1];
							temp.arr[k][2]=arr[i][2];
							i++;
							k++;
						}
						else if(arr[i][1]>m2.arr[j][1])
						{
							temp.arr[k][0]=m2.arr[j][0];
							temp.arr[k][1]=m2.arr[j][1];
							temp.arr[k][2]=m2.arr[j][2];
							k++;
							j++;
						}
					}
					
					else if(arr[i][0]<m2.arr[j][0])
					{
							temp.arr[k][0]=arr[i][0];
							temp.arr[k][1]=arr[i][1];
							temp.arr[k][2]=arr[i][2];
							i++;
							k++;
					}
					else
					{
							temp.arr[k][0]=m2.arr[j][0];
							temp.arr[k][1]=m2.arr[j][1];
							temp.arr[k][2]=m2.arr[j][2];
							k++;
							j++;
					}
				}	
				
				while(i<=arr[0][2])
				{
							temp.arr[k][0]=arr[i][0];
							temp.arr[k][1]=arr[i][1];
							temp.arr[k][2]=arr[i][2];
							i++;
							k++;
				}
					
				while(j<=m2.arr[0][2])
				{
							temp.arr[k][0]=m2.arr[j][0];
							temp.arr[k][1]=m2.arr[j][1];
							temp.arr[k][2]=m2.arr[j][2];
							k++;
							j++;
				}
			return temp;
			
		}
		
};

int main()
{

	int r1,c1,r2,c2;
	cout<<"\n enter the no. of rows and columns of 1st sparse matrix :";
	cin>>r1>>c1;
	sparsematrix m1(r1,c1);
	m1.getmatrix();
	m1.display();
	m1.convert();
	cout<<"\n sparse representation\n";
	m1.display();
	
	cout<<"\n enter the no. of rows and columns of 1st sparse matrix :";
	cin>>r2>>c2;
	sparsematrix m2(r2,c2);
	m2.getmatrix();
	m2.display();
	m2.convert();
	cout<<"\n sparse representation\n";
	m2.display();

	if(r1==r2 && c1==c2)	
	{
		cout<<"\n sparse addition possible !";
		sparsematrix m3=m1+m2;
		m3.display();
	}
	else
		cout<<"\n sparse addition not possible !";
						
return 0;
}

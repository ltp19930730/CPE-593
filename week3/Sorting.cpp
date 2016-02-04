#include <iostream>
#include <stdlib.h>
using namespace std;

//time complexity is O(n^2)
void SelectionSort(int A[],int n){
for(int i = 0;i <= n-2; i++)
{
	int imin = i;
	for(int j = i+1;j <n;j++)
	{
		if(A[j]<A[imin])
		{
			imin=j;
		}
	}
	int temp=A[i];
	A[i]=A[imin];
	A[imin]=temp;
}
}

void BubbleSort(int A[],int n)
{    
	for(int i=1;i<n;i++)
	{   int flag=0;
		for(int j=0;j<n-i;j++)
		{
			if(A[j]>A[j+1])
			{
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				flag=1;
			}
		}
		if(flag==1)
		{
			break;
		}
	}

}

void insertSort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{   
		int hole = i;
		int value=a[i];
		while(hole>0&&a[hole-1]>value)
		{
             a[hole]=a[hole-1];
             hole--;
		}
		a[hole]=value;
	}
}


void print(int A[],int n)
{
for(int i=0;i<n;i++)
  {
  	cout<<A[i]<<"\t";
  }
 cout<< endl;
}

int main(){
  int a[5]={5,1,3,2,4};
  int b[6]={3,1,2,4,4,6};
  int c[7]={10,4,3,2,1,5,6};
  SelectionSort(a,sizeof(a)/4);
  BubbleSort(b,sizeof(b)/4);
  insertSort(c,sizeof(c)/4);
  print(a,sizeof(a)/4);
  print(b,sizeof(b)/4);
  print(c,sizeof(c)/4);

  return 0;
}
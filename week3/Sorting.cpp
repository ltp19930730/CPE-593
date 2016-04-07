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


void quicksort (int* a, int start, int end)  
{  
  
    int i=start, j=end, h;  
  
    // comparison element x  
    int x=a[rand()%(end-start+1)+start];  
  
    //  partition  
    while(i<=j)  
    {      
        while (a[i]<x) i++;   
        while (a[j]>x) j--;  
        if (i<=j)  
        {  
            h=a[i]; a[i]=a[j]; a[j]=h;  
            i++; j--;  
        }  
    } 
  
    //  recursion  
    if (start<j) quicksort(a, start, j);  
    if (i<end) quicksort(a, i, end);  
}  

int main(){
  int a[5]={5,1,3,2,4};
  int b[6]={3,1,2,4,4,6};
  int c[7]={10,4,3,2,1,5,6};
  int d[11]={3,4,10,2,5,15,11,10,1,21,6};
  SelectionSort(a,sizeof(a)/4);
  BubbleSort(b,sizeof(b)/4);
  insertSort(c,sizeof(c)/4);
  quicksort(d,0,10);
  print(a,sizeof(a)/4);
  print(b,sizeof(b)/4);
  print(c,sizeof(c)/4);
  print(d,11);
  return 0;
}
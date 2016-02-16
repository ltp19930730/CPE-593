#include <iostream>
#include <fstream>
using namespace std;

void match(int* a,int parent,int n)
{
	int left= 2*parent+1;
	int right= 2*parent+2;

	int largest=parent;

	if(left>=n)
		return;
	if(right>=n)
	{
		if(a[left]>a[parent])
		{
			swap(a[left],a[parent]);
			match(a,left,n);
		}
		return;
	}
	if(a[left]>a[right])
	{
		if(a[left]>a[parent])
		{
			swap(a[left],a[parent]);
			match(a,left,n);
		}
	}else{
		if(a[right]>a[parent])
		{
			swap(a[right],a[parent]);
			match(a,right,n);
		}
	}
	
}

void makeHeap(int* a,int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		match(a,i,n);
	}
}

void heapsort(int* a,int n)
{
	makeHeap(a,n);
	for(int i=n-1;i>=1;i--)
	{
		swap(a[0],a[i]);
		match(a,0,i);
	}
}
int main() {
	ifstream f("hw3.dat");
	int n;
  f >> n;
	int x[n]; //  int*x  =  new int[n];
	for (int i = 0; i < n; i++)
		f >> x[i];
	heapsort(x, n);
	for (int i = 0; i < n; i++)
		cout << x[i] << ' ';
	//delete [] x;
}
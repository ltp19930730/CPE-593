#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

void match(int *a,int parent,int n)
{
	int left=parent*2+1;
	int right=parent*2+2;
	if(left>=n)
	{
		return;
	}
	if(right>=n)
	{
		if(a[left]>a[parent])
		{
			swap(a[left],a[parent]);
			match(a,left,n);
		}
		return;
	}
	if(a[right]>a[left])
	{
		if(a[right]>a[parent])
		{
			swap(a[right],a[parent]);
            match(a,right,n);
		}
	}else{
		if(a[left]>a[parent])
		{
			swap(a[left],a[parent]);
			match(a,left,n);
		}
	}
}

void makeheap(int *a,int n){
	for(int i=n/2-1;i>=0;i--)
	{
		match(a,i,n);
	}
}

void heapsort(int *a,int n)
{
	makeheap(a,n);
	for(int i=n-1;i>=0;i--){
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
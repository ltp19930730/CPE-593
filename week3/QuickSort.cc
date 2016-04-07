//data: 2/5/2016
//author:Tianpei Luo
//HW3-Sorting
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;


int part(int* a,int start,int end)
{
 	int pivot=a[end];
 	int index=start;
 	for(int i=start;i<end;i++)
 	{
 		if(a[i]<pivot)
 		{
 			swap(a[i],a[index]);
 			index++;
 		}
 	}
 	swap(a[index],a[end]);
 	return index;
 }



void Quicksort(int* a,int start,int end)
{
	if(start<end)
	{   
		int index=part(a,start,end);
  	    Quicksort(a,start,index-1);
	    Quicksort(a,index+1,end); 
	}
    
}


int main()
{
   fstream file;
   file.open("hw3.dat");
   int n=0;
   file>>n;
   int* a;
   a=new int[n];
   for(int i=0;i<n;i++)
   {
   	file >> a[i];
   }
   Quicksort(a,0,n-1);

   for(int i=0;i<n;i++)
   {
   	cout<<a[i]<<"\t";
   }
   delete [] a;
   return 0;
}
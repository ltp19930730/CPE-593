//data: 2/5/2016
//author:Tianpei Luo
//HW3-Sorting
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;


void Quicksort(int* a,int start,int end)
{   
   int i=start;
   int j=end;
   if(i>=j)
   {
      return;
   }
 	int pivotn=rand()%(end-start+1)+start;
 	int pivot=a[pivotn];
   while(i<j)
   {
      while(a[i]<=pivot)
      {
         i++;
      }
      while(a[j]>pivot)
      {
         j--;
      }
      if(i<j)
      {    
       swap(a[i],a[j]);
         }
   }
 
   
   Quicksort(a,start,i);
   Quicksort(a,i+1,end);
 	
 }

int main()
{
   fstream file("hw3.dat");
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
//data: 2/5/2016
//author:Tianpei Luo
//HW2b-OptimizedSorting
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

using namespace std;





void Quicksort(int* a,int start,int end)
{
	if(start<end)
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

	  Quicksort(a,start,index-1);
	  Quicksort(a,index+1,end); 
	}
   
}
void insertsort(int*x,int n)
{
	for (int i = 1; i < n; i++) {
			if (x[i] >= x[i-1])
				continue;
			int temp = x[i];
			int j;
			for (j = i-1; j >= 0; j--) {
				if (x[j] > temp)//change x[i] to temp
					x[j+1] = x[j];
				else {
					break;
				}
			}
			x[j+1] = temp;
		}
}
void QuicksortOpt(int* a,int start,int end,int k)
{
	if(start<end)
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
      if(index-1-start>k)
      {
	  QuicksortOpt(a,start,index-1,k);
	  }else{
	  	insertsort(a,k);
	  }
	  if(end-index-1>k)
	  {
	  QuicksortOpt(a,index+1,end,k); 
	  }else{
	  	insertsort(a,k);
	  }
	}   
}


int main()
{   
   int k=0;  
   while(k<100000){
   clock_t start,finish;
    start=clock();
   long long n=10000000;
   int* a;
   a=new int[n];
   for(long long i=0;i<n;i++)
   {
   	 a[i]=rand() % (n - 2) + 2;
   }
   QuicksortOpt(a,0,n-1,k);

   delete [] a;

   finish=clock();
   cout << "k="<<k<<" time:" <<finish-start   << "/" << CLOCKS_PER_SEC  << " (s) "<< endl;
   k+=500;
}
   return 0;
}
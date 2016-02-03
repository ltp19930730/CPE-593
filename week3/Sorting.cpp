#include <iostream>
#include <stdlib.h>
using namespace std;

void SelectionSort(int A[],int n){
for(int i = 0;i < n-2; i++)
{
	int imin = i;
	for(int j = i+1;j < n-1;j++)
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

int main(){
  int a[5]={5,1,3,2,4};
  SelectionSort(a,sizeof(a)/4);
  for(int i=0;i<5;i++)
  {
  	cout<<a[i];
  }
  return 0;
}
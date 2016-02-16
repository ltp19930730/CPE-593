#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int BinarySearch(int* a,int n,int number)
{
	int start=0;
	int end=n-1;
	if(a[start]>number||a[end]<number){
		return -1;
	}
	while(start<=end)
	{
		int mid=start+(end-start)/2;
		if(a[mid]==number)
		{
			return mid;
		}else if(a[mid]>number)
		{
			end=mid-1;
		}else{
			start=mid+1;
		}
	}
	return -1;
}

int main()
{
	string garbage;
	int n;
	int number;
	int garbageNum;
    ifstream file("HW3.txt");
    file>>garbage;
    file>>garbageNum;
    while(file>>n)
    { 
    	int *a=new int[n];
    	for(int i=0;i<n;i++)
    	{
           file>>a[i];
    	}
    	file>>number;
    	int result=BinarySearch(a,n,number);
    	if(result!=-1){
    		cout<<number<<" "<<result<<endl;
    	}else{
    			cout<<"NOT FOUND "<<number<<endl;
    	}
    	delete [] a;

    }
	return 0;
}
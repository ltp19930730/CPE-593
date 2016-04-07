#include <iostream>
using namespace std;
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
int main()
{
	int a[5]={4,3,1,2,10};
	insertsort(a,5);
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
}
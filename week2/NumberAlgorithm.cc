#include <iostream>
#include <algorithm>
using namespace std;
//time complexity is O(logN)
int trialdivisionGcd(int a,int b)
{
	int gcd =1;
	for(int i=2;i<=min(a,b);i++)
	{
		if(a%i==0&&b%i==0)
		{
			gcd=i;
		}
		
	}
	return gcd;
}
int gcd(int a,int b)
{
	while(b)
	{
		int temp=a;
		a=b;
		b=temp%b;
	}
	return a;
}
int recursivegcd(int a,int b)
{
	if(b==0)
		return a;
	return recursivegcd(b,a%b);
}
//lcm(a*b)=a*b/gcd(a,b);
int main()
{
	cout<<gcd(12,18);
	cout<<recursivegcd(12,6);
	cout<<trialdivisionGcd(3025,1025);
}
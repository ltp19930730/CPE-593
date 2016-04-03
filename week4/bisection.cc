#include <iostream>
#include <cmath>
#include <utility>
#include <iomanip>
using namespace std;
//find the root 
//using #if 0 #endif is better than /* */
#if 0
inline void swap(double&a, double&b)
{
	double temp=b;
	b=a;
	a=temp;
}
#endif

double f(double x)
{
	return x*x-2;
}

typedef double(*F)(double x);

double bisection(F f,double a, double b, double eps)
{
	if(f(a)>0&&f(b)<0)
	{
		swap(a,b);
	}
	if(f(a)*f(b)>0){
		throw "No Root!";
	}
	double guess;
	do{
		guess=(a+b)/2;
		double y=f(guess);
		if(y>0){
			b=guess;
		}else if (y<0){
			a=guess;
		}
	}while(fabs(b-a)>eps);
	return (a+b)/2;
}
int main() {
	try {
		double eps = 0.1;
		for (int i = 1; i <= 5; i++, eps *= 0.1)
			cout << setprecision(15) << eps << '\t' << bisection(f, 0, 3, eps) << '\n'; 

	} catch(const char* msg) {
		cout << msg << '\n';
	}
}
#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
  a^=b;
  b^=a;
  a^=b;
}
void generate()	

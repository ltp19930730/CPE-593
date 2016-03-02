#include <iostream>
using namespace std;

#if 0
class badGrowArray
{
 private:
 	int *p;
 	int len;
 public:
 	badGrowArray()
 	{
 		p=nullptr;//O(1);
 		len=0;
 	}
 	~badGrowArray()
 	{
 		delete [] p;//O(1);
 	}
 	void add(int v)
 	{
 		int *temp = p;
 		p=new int[len+1];//O(1) ;in java it is O(n)
 		for(int i=0;i<len;i++)//O(n)
 		{
 			p[i]=temp[i];
 		}
 		p[len+1]=v;//O(1)
 		len++;
 		delete [] temp;
 	}
};

int main()
{
	badGrowArray a;
	for(int i=0;i<100000;i++)
	{
	a.add(i); // O(n*n) so it is bad growing array;
	}

}
#endif

class GrowArray
{
 private:
 	int *p;
 	int size;
 	int used;
 public:
 	GrowArray():p(nullptr),size(0),used(0)
 	{

 	}

 	
 	~GrowArray()
 	{
 		delete [] p;//O(1);
 	}
 	void addStart(int v)
 	{
 		int *temp = p;
 		p=new int[len+1];//O(1) ;in java it is O(n)
 		for(int i=1;i<=len;i++)//O(n)
 		{
 			p[i]=temp[i-1];
 		}
 		p[0]=v;//O(1)
 		len++;
 		delete [] temp;
 	}
 	void addEnd(int v)  //o( )
 	{

 	}
 	int capcity() const {
 		return size;
 	}

 	int getUsed() const {
        return used;
 	}
 	int get(int i) const //O(1)
 	{    
 		if(i<0||i>=used)
 			throw "Die!";
 		return p[i];
 	}
 	void set(int i,int v)
 	{
 		if(i<0||i>=used)
 			throw "Die!";
 		p[i] = v;   //O(1)
 	}
};

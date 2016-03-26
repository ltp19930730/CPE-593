//data: 2/24/2016
//author:Tianpei Luo
//HW4a-GrowArray
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
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
 		if(size==used){
 		int *temp = p;
 		size=size?(2*size):(size+1);
 		p=new int[size];//O(1) ;in java it is O(n)
 		for(int i=1;i<=used;i++)//O(n)
 		{
 			p[i]=temp[i-1];
 		}
 		p[0]=v;//O(1)
 		used++;
 		delete [] temp;	
 	    } else {
 	    	int *temp = p;
 	    	for(int i=1;i<=used;i++)//O(n)
 		{
 			p[i]=temp[i-1];
 		}
 		     p[0]=v;
 		     used++;
 		     delete [] temp;
 	    }
 	}
 	
 	void addEnd(int v)  
 	{
 		if(size==used){
 		int *temp = p;
 		size=size?(2*size):(size+1);
 		p=new int[size];//O(1) ;in java it is O(n)
 		for(int i=0;i<used;i++)//O(n)
 		{
 			p[i]=temp[i];
 		}
 		p[used]=v;//O(1)
 		used++;
 		delete [] temp;
 	    } else {
 	    	
 		     p[used]=v;
 		     used++;
 		     
 	    }

 	}
 
    void removeStart(int n)
    { 
    	int *temp = p;
    	p = new int[used-n];//O(1)
    	for(int i=n;i<used;i++)//O(n)
    	{
    		p[i-n]=temp[i];
    	}
    	used=used-n;
    	delete [] temp;

    }
    void removeEnd(int n)
    {
    	int *temp = p;
    	p = new int[used-n];//O(1)
    	for(int i=0;i<used-n;i++) //O(n)
    	{
    		p[i]=temp[i];
    	}
    	used=used-n;
    	delete [] temp;

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
 	
 	void print()
 	{
 		for(int i=0;i<used;i++)
 		{
 			cout << p[i]<<'\t';
 		}
 		cout<<endl;
 	}
};

int main()
{
    ifstream file("HW4a.txt");
    int number;
    bool ADD_FRONT=false;
    bool ADD_BACK=false;
    bool REMOVE_FRONT=false;
    bool REMOVE_BACK=false;
    string instruct;
    int *arrNum;
    
    int len=0;

    GrowArray a;
    while(file>>instruct){
    	
    	if(instruct=="ADD_FRONT")
    	{
    		arrNum=new int[10];

    		ADD_FRONT=true;
    		ADD_BACK=false;
    		REMOVE_FRONT=false;
            REMOVE_BACK=false;

    	}else if(instruct=="ADD_BACK")
    	{
   
    		if(len!=0)
    		{  
    			for(int i=len-1;i>=0;i--)
    			{
    				a.addStart(arrNum[i]);
    			}
    			len=0;
    			delete []arrNum;
    		}
    		ADD_FRONT=false;
    		ADD_BACK=true;
    		REMOVE_FRONT=false;
            REMOVE_BACK=false;
    	}else if(instruct=="OUTPUT")
    	{
    		ADD_FRONT=false;
    		ADD_BACK=false;
    		REMOVE_FRONT=false;
            REMOVE_BACK=false;
    		a.print();
    	}else if(instruct=="REMOVE_FRONT")
    	{
    		cout<<"hh";
            REMOVE_FRONT=true;
            REMOVE_BACK=false;
            ADD_FRONT=false;
    		ADD_BACK=false;
    	}else if(instruct=="REMOVE_BACK")
    	{ 
    		REMOVE_BACK=true;
    		REMOVE_FRONT=false;
    		ADD_FRONT=false;
    		ADD_BACK=false;
    	}

    	if(isdigit(instruct[0])&ADD_FRONT)
    	{
    		number=atoi(instruct.c_str());
    		arrNum[len]=number;
    		len++;
    		
    	}else if(isdigit(instruct[0])&ADD_BACK)
    	{
    		number=atoi(instruct.c_str());
    		a.addEnd(number);
    	}else if(isdigit(instruct[0])&REMOVE_FRONT)
    	{
    		number=atoi(instruct.c_str());
    		a.removeStart(number);
    	}else if(isdigit(instruct[0])&REMOVE_BACK)
    	{
    		number=atoi(instruct.c_str());
    		a.removeEnd(number);
    	}
    }


    file.close();

	return 0;
}
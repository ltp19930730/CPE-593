#include <iostream>
#include <string>
using namespace std;

class Hashmap{
private:
	string** table;
	int size;
	int used;
	int limit;
	int hist[11];

	int hash(const string& s) const
	{
		int sum=0;
		for(int i=0;i<s.size();i++)
			sum=(sum*26+s[i])%size;
		cout<<"the hash number:"<<sum<<endl;
		return sum;
	}
public:
	Hashmap(int initialSize)
	{
		int i;
		for(i=1;i<initialSize;i*=2)
			;
		cout<<i<<endl;
		limit = i / 2;
		size = limit*2;
		cout<<size;
		table = new string *[size];
		for(int i = 0;i<size;i++)
			table[i] = nullptr;
		used = 0;
		for(int i=0;i<11;i++)
			hist[i]=0;
	}
	~Hashmap()
	{
		for(int i =0;i<size;i++)
			delete table[i];
		delete [] table;
	}
	void addString(const string& s)
	{
		used++;
		int bin=hash(s);
		int count = 0;
		while(table[bin]!=nullptr)
		{
			bin=(bin+1)%size;
			count ++;
		}
		hist[count]++;
		table[bin]=new string(s);
		cout<<*table[bin]<<endl;
	}
	void searchIntable(const string& s)
	{
		int index=hash(s);
		if(table[index]!=nullptr){
		
		if(*table[index]==s)
		{
			cout<<"found it !"<<endl;
		}
	   }else{
	   	cout<<"not found yet";
	   }
	}

};

int main()
{
	Hashmap m(10000);
	
	string s;

	for(int i=0;i<5;i++)
	{
		cout<<"Please enter an string!";
		getline(cin,s);
		m.addString(s);
	}

    for(int i=0;i<5;i++)
	{
		cout<<"Please found it in the dictionary:";
		getline(cin,s);

	    m.searchIntable(s);
	}
	
}
#include <iostream>

using namespace std;
#if 0

class growarr{

private:
	int *data;
	int used;
	int size;
public:
	growarr()
	{
		size=1;
		used=0;
		data=new int [size];
	}
	~growarr()
	{
		delete [] data;
			}

	void grow()
	{
		size=size*2;
		int *temp=new int[size];
		for(int i=0;i<used;i++)
		{
            temp[i]=data[i];
		}
		delete [] data;
		data=temp;
	}
    void addfirst(int v)
    {
    	if(used==size)
    	{
    		grow();
    	}
    	for(int i=0;i<used;i++)
    	{
    		data[i+1]=data[i];
    	}
    	data[0]=v;
    	used++;0
    }
    void addLast(int v)
    {
    	if(used==size)
    	{
    		grow();
    	}
        data[used]=v;
        used++;
    }
    void deletelast()
    {
    	used--;
    }

};
#endif
class linklist{
private:
	class Node{
	public:
		Node* next;
		int data;
		Node(Node*n,int v):next(n),data(v)
		{

		}
	};
	Node* head;
	Node* tail;
public:
	linklist()
	{
		head=nullptr;
		tail=nullptr;
	}
	~linklist()
	{
		Node* temp;
		while(head!=nullptr)
		{
			temp=head;
			head=head->next;
            delete [] temp; 
		}

	}
	void addend(int v)
	{ 
		if(head==nullptr)
		{
			head=new Node(nullptr,v);
			tail=head;
			return;
		}
		Node*temp=new Node(nullptr,v);
		tail->next=temp;
		tail=temp;


	}
	void addstart(int v)
	{
		Node*temp =new Node(head,v);
		head =temp;
	}
	void insert(int pos,int v)
	{
		Node*temp=head;
		for(int i=0;i<pos;i++)
		{
			temp=temp->next;
		}
		Node* node = new Node(temp->next,v);
        temp->next=node;    
	}
	void print()
	{    
		Node*temp=head;
		while(temp!=nullptr)
		{
			cout<<temp->data;
			temp=temp->next;
		}
	}
};

int main()
{
	linklist a;
	a.addend(1);
	a.addend(2);
	a.addend(4);
	a.addend(6);
	a.addend(22);
	a.addstart(0);
	a.insert(2,3);
	a.print();
}
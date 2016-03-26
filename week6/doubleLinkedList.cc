//data: 3/12/2016
//author:Tianpei Luo
//HW4b - Double Linked List class
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class doubleLinklist
{
private:
	class node
	{
      public:
      	node *next;
      	node *prev;
      	int date;
      	node(int v):date(v),next(nullptr),prev(nullptr){}
      	node(int v,node *prev,node *next):date(v),next(next),prev(prev){}
	};
	node *head;
	node *tail;
public:
	doubleLinklist():head(nullptr),tail(nullptr){}
	~doubleLinklist()
	{
		while(head!=nullptr)
		{
          node* temp=head;
          head=head->next;
          delete [] temp;
		}
	}
	void addFront(int v)
	{  
       if(head==nullptr)
       {
       	head=new node(v);
       	tail = head;
       }else{
        node* temp=head;
        head = new node(v,nullptr,temp);
        temp->prev=head;
       }
	}
	void addBack(int v)
	{
		if(head==nullptr)
		{
			head=new node(v);
			tail=head;
		}else{
			node *temp=tail;
			tail = new node(v,temp,nullptr);
			temp->next=tail;
		}
	}
	void deleteStart(int n)
	{
		if(head==nullptr)
		{
			cout<<"the list is empty";
			return;
		}
		for(int i=0;i<n;i++)
		{
		       node*temp = head;
		       head=head->next;
		       delete [] temp;
		}
		head->prev=nullptr;
	}
	void deleteEnd(int n)
	{
		if(head==nullptr)
		{
			cout<<"the list is empty";
			return;
		}
		for(int i=0;i<n;i++)
		{
		       node*temp = tail;
		       tail=tail->prev;
		       delete [] temp;
		}
		tail->next=nullptr;
	}


	void Insert(int v,int pos)
	{
		node* temp = head;
		for(int i=0;i<pos;i++)
		{
			temp=temp->next;
		}
		node *p=new node(v,temp,temp->next);
		temp->next->prev=p;
		temp->next=p;
	} 

	void printList()
	{   
		node* temp=head;
		while(temp!=nullptr)
		{
			cout<<temp->date<<'\t';
			temp=temp->next;
		}

	}
	class Iterator{
	private:
		node* p;
	public:
		Iterator(node* a):p(a){}
		Iterator(const doubleLinklist& list)
		{
			p=list.head;
		}
		bool notEnd()const{
			return p!=nullptr;
		}
		void operator++(){
			p=p->next;
		}
		void operator--(){
			p=p->prev;
		}
		int val() const{
			return p->date;
		}
	};
		Iterator end() const{
			if(head==nullptr)
			{
				return Iterator(nullptr);
			}
			node* p = head;
			for(;p->next!=nullptr;p=p->next)
				;
			return Iterator(p);
		}
	
};
int main()
{
	doubleLinklist a;
	ifstream file("HW4b.txt");
    string instruct;
    bool ADD_FRONT=false;
    bool ADD_BACK=false;
    bool REMOVE_FRONT=false;
    bool REMOVE_BACK=false;
    int *arrNum;
    int len=0;
    int number;
    while(file>>instruct){
   

    	if(instruct=="ADD_FRONT")
    	{
          ADD_FRONT=true;
          arrNum = new int[100];
    	}else if(instruct=="ADD_BACK")
    	{
    		ADD_BACK=true;
    	}else if(instruct=="REMOVE_FRONT")
    	{
    		ADD_BACK=false;
    		REMOVE_FRONT=true;
    		REMOVE_BACK=false;
    	}else if(instruct=="REMOVE_BACK")
    	{
    		ADD_BACK=false;
    		REMOVE_FRONT=false;
    		REMOVE_BACK=true;
    	}

    	if(isdigit(instruct[0])&ADD_FRONT)
    	{
    		number=atoi(instruct.c_str());
    		arrNum[len]=number;
    		len++;	

    	}

    	if(isdigit(instruct[0])&ADD_BACK)
    	{
           number=atoi(instruct.c_str());
    		a.addBack(number);
    	}
    	if(isdigit(instruct[0])&REMOVE_FRONT)
    	{
           number=atoi(instruct.c_str());
    		a.deleteStart(number);
    	}
    	if(isdigit(instruct[0])&REMOVE_BACK)
    	{
           number=atoi(instruct.c_str());
    		a.deleteEnd(number);
    	}


    	if(!isdigit(instruct[0])&&len!=0)
    	{
    		for(int i=len-1;i>=0;i--)
    		{
    			a.addFront(arrNum[i]);
    		}
    		len=0;
    		delete []arrNum;
    		ADD_FRONT=false;
    	}

    	if(instruct=="OUTPUT")
    	{
             a.printList();
             cout<<endl;
    	}

    }
   file.close();




    return 0;
}
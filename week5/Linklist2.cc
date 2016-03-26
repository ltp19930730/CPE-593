#include <iostream>
using namespace std;

class Linkedlist{
   private:
   	class Node{
      public:
      	int val;
      	Node* next;
   	};
   	Node* head;
    Node* tail;
   public:
   	Linkedlist()
   	{
   		head=nullptr;
      tail=nullptr;
   	}
   	void addStart(int n)
   	{//O(1)
       
       	 Node* p = new Node();
         p->val=n;
         p->next=head;
         head=p;
         if(head->next==nullptr)
         {
          tail=p;
         }
      
   	}
   	void addEnd(int n)
   	{//O(1)
   		Node* p = new Node();
      p->val=n;
      if(tail==nullptr)
      {
         
         p->next=tail;
         tail=p;
         head=p;
         return ;
      }
      tail->next=p;
      tail=tail->next;
         
   	 }
    void removeStart()
    { //O(1)
      	Node* temp=head;
      	head=head->next;
      	delete temp;
      
    }
    void removeEnd()
    {//O(1)
    	Node* p;
    	for(p=head;p->next->next!=nullptr;p=p->next)
    	;
        Node*temp=p->next;
        p->next=nullptr;
        delete temp;
    }

   	void get()
   	{//O(n)
   		Node*p=head;
   		for(;p!=nullptr;p=p->next)
   		{
   			cout<<p->val<<'\t';
   		}
   	}

};
int main()
{
	Linkedlist a;
	for(int i=0;i<20;i+=2)
	{
		a.addEnd(i);
	}

	a.get();
	return 0;
}
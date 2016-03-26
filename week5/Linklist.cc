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
   public:
   	Linkedlist()
   	{
   		head=nullptr;
   	}
   	void addStart(int n)
   	{//O(1)
       
       	 Node* p = new Node();
         p->val=n;
         p->next=head;
         head=p;
      
   	}
   	void addEnd(int n)
   	{//O(n)
   		if(head==nullptr){
   		Node* p = new Node();
   		p->val=n;
   		p->next=head;
   		head=p;
   		return ;
   	    }
   	    Node* temp=head;
   	    while(temp->next!=nullptr){
         temp=temp->next;
   	    }
   	    Node *p =new Node();
   	    temp->next=p;
   	    p->val=n;
   	    p->next=nullptr;
   	    #if 0
   	     Node*p;
   	     for(p=head;p->next != nullptr; p = p->next)
   	     ;
   	     p->next=new Node();
   	     p->next->val=n;
   	     p->next->next=nullptr;
   	#endif
   	 }
    void removeStart(int n)
    { //O(n)
      for(int i=0;i<n;i++)
      {
      	Node* temp=head;
      	head=head->next;
      	delete temp;
      }
    }
    void removeEnd()
    {//O(n)
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
	a.removeStart(2);
	a.removeEnd();
	a.get();
	return 0;
}
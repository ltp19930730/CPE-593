#include<iostream>
using namespace std;
#if 0
class Growarray{
private:
  int *data;
  int size;
  int used;
  void grow()
  {
    size*=2;
    int *temp;
    temp=new int[size];
    for(int i=0;i<used;i++)
    {
      temp[i]=data[i];
    }
    delete[] data;
    data = temp;
  }
public:
  Growarray()
  {
    size=1;
    used=0;
    data=new int[size];
  }
  ~Growarray()
  {
    delete [] data;
  }
  void addfirst(int v)
  {
    if(used==size)
    {
      grow();
    }

    for(int i=used;i>0;i--)
    {
      data[used]=data[used-1];
    }
    data[0]=v;
    used++;
  }
  void addEnd()
  {
    if(size==used)
    {
      grow();
    }
    data[used++]=v;
  }
  void deletelast()
  {
    used--;
  }
};
#endif
//double linkedlist

class Linkedlist{
private:
  class Node{
  public:
    int val;
    Node *prv;
    Node *next;
    Node(int v,Node *prv,Node *next):val(v),prv(prv),next(next){}
  };
  Node *head;
  Node *tail;
public:
  Linkedlist(){
    head=nullptr;
    tail=nullptr;
  }
  /*~Linkedlist()
  {
    Node *p;
    while(head!=nullptr)
    {
      p=head;
      head=head->next;
      delete p;
    }
  }*/
  void addLast(int v)
  {
     Node*p = new Node(v, nullptr, head);
     if(head==nullptr)
     {
       head=p;
       tail=p;
     }else{
     head->prv=p;
     head=p;
   }
  }
  void addEnd(int v)
  {
    Node *temp;
    temp = new Node(v,tail,nullptr);
    if(tail==nullptr)
    {
      head=temp;
      tail=temp;
    }else{
    tail->next=temp;
    tail=temp;
  }
  }

  void output()
  {

    Node*p =tail;
    while(p!=nullptr)
    {
      cout<<p->val<<'\t';
      p=p->prv;
    }
  }
  void insert(int pos,int v)
  {
    Node *p=head;
    for(int i=0;i<pos;i++)
    {
      p=p->next;
    }
    Node *node= new Node(v,nullptr,nullptr);
    p->prv->next=node;
    node->prv=p->prv;
    p->prv=node;
    node->next=p;
  }
};

int main()
{
  Linkedlist a;
  a.addLast(1);
  a.addLast(2);
  a.addLast(3);
  a.addEnd(4);
  a.insert(2,10);
  a.output();
  return 0;
}

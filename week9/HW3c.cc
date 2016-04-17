//HW3C optional build a list
//date: 04/16/2016
//BY TP Luo
#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;
class List{
private:
  int start;
  int end;
  int* list;
public:
  //O(n)
  List(int start, int end):start(start),end(end){
    list = new int [end+1];
    for(int i=start;i<=end;++i)
    {
      list[i]=1;

    }
  }
  ~List(){
    delete [] list;
  }
  // O(num*n)
  void remove(int num){
    int index=1;
    while(index*num<=end)
    {
      list[index*num]=0;
      ++index;
    }
  }

  //o(n);
  void print(){
    for(int i=start;i<=end;++i){
      if(list[i]==1){
        cout<<i<<'\t';
      }
    }
  }
  //o(n);
  double sum_total(){
     double sum=0;
     for(int i=start;i<=end;++i){
       if(list[i]==1){
         sum+=i;
       }
     }
     return sum;
  }
};

int main()
{
  DWORD begin, end;
  begin =  GetTickCount();
  int input_start;
  int input_end;
  int input_numTodelete;
  int index=0;
  int num;
  cin>>input_start;
  cin>>input_end;
  cin>>input_numTodelete;
  List a(input_start,input_end);
  //remove the number in the list
  while(index<input_numTodelete){
    cin>>num;
    a.remove(num);
    ++index;
  }
  double sum = a.sum_total();
  end = GetTickCount();
  a.print();
  cout<< "the total of the numbers that left is "<<sum<<endl;
  cout<<"The run time is:"<<(end-begin)<<"ms!"<<endl;//输出运行时间
  return 0;
}

//author:Tianpei Luo
//date:04/03/2016
//homework:Boggle

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <memory.h>
using namespace std;

class TrieNode
{
public:
  TrieNode *next[26];
  bool is_word;
  TrieNode(bool b = false)
  {
    memset(next,0,sizeof(next));
    is_word=b;
  }
};

class Trie
{
private:
  TrieNode *root;
public:
  Trie()
  {
    root = new TrieNode();
  }

  void add(string s)
  {
     TrieNode *p=root;

    for(int i=0;i<s.size();i++)
    {
      if(s[i]<97)
      {
        s[i]+=32;
      }
      if(p->next[s[i]-'a']==NULL)
      {
        p->next[s[i]-'a']=new TrieNode();
      }
      p=p->next[s[i]-'a'];
    }
      p->is_word=true;
  }
  bool contains(string s)
  {
    TrieNode *p = find(s);
    return p != NULL && p -> is_word;
   }

   bool containsPrefix(string s)
   {
     return find(s)!=NULL;
   }
   TrieNode* find(string key)
   {
     TrieNode *p=root;
     for(int i=0;i<key.size()&&p!=NULL;i++)
     {
       if(key[i]<97)
       {
         key[i]+=32;
       }
       p=p->next[key[i]-'a'];
     }
     return p;
   }
};
//boggle algorithm
void boggle(vector<string>&output,Trie dict,char **board,char word[],int k,int row,int col,int side)
{
  if(row>=0 && row<side && col>=0 && col<side && board[row][col] != '\0')
  {
    word[k++] = board[row][col];
    word[k]='\0';

   if(k>=3)
    {
      if(dict.contains(word))
     {
       if(find(output.begin(),output.end(),word)==output.end()){
        output.push_back(word);
       }
     }
    }

  if(dict.containsPrefix(word))
   {
      char c = board[row][col];
      board[row][col]='\0';  // mark this alphabet for having been used

      //backtraking all the possible
      boggle(output,dict, board, word, k, row-1, col-1,side);
      boggle(output,dict, board, word, k, row-1, col,side);
      boggle(output,dict, board, word, k, row-1, col+1,side);
      boggle(output,dict, board, word, k, row, col-1,side);
      boggle(output,dict, board, word, k, row, col+1,side);
      boggle(output,dict, board, word, k, row+1, col-1,side);
      boggle(output,dict, board, word, k, row+1, col,side);
      boggle(output,dict, board, word, k, row+1, col+1,side);
      board[row][col] = c;
    }
   }
  }


int main()
{
  Trie dict;
  fstream dict_file("dictionary.dat");
  fstream bog_file("boggle.dat");
  string word_dict;
  vector<string>output;
  int side;
  char alph_b;
  char **board;
  char word[20];
  int row=0,col=0;

  //add the dat file into the Trie structure
  while(dict_file>>word_dict)
  {
    dict.add(word_dict);
  }

  dict_file.close();

  bog_file>>side;
  cout<<"the boggle is an "<<side<<"x"<<side<<" square!"<<endl;
  board = new char*[side];
  for(int i=0;i<side;i++)
  {
    board[i]=new char[side];
  }

  //create the board for the game boggle
  while(bog_file>>alph_b)
  {
        board[row][col]=alph_b;
        col++;
        if(col>=4)
        {
          row++;
          col=0;
        }
  }
bog_file.close();

//find out all the possible word in this game
for(int i=0;i<side;i++){
  for(int j=0;j<side;j++)
  {
    boggle(output,dict,board,word,0,i,j,side);
  }
}
//out put all the result
for(int i=0;i<output.size();i++)
{
  cout<<output[i]<<" is a word"<<endl;
}

//cout<<output.size();

  return 0;
}

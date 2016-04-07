//HW:Trie
//BY Tianpei Luo
//date: 3/25/2016
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Trie
{
private:
	class Node
	{
     public:
     	Node()
     	{
           isWord=false;
           for(int i=0;i<26;i++)
           {
            child[i]=nullptr;
           }
     	}
     	Node* child[26];
        bool isWord;

	};
	Node* head;
public:
	Trie(){
		head= new Node();
	};
	~Trie()
	{
		delete[] head;
	};
	void loadWord(const string& word)
	{
		Node* current = head;
		for(int i=0;i<word.length();i++)
		{
			int letter = (int)word[i]-(int)'a';
			if(current->child[letter]==nullptr)
			{
				current->child[letter] = new Node();
			}
			current = current->child[letter];
		}
        current->isWord=true;
	}
	bool search(const string& word)
	{
		Node* current = head;
        for(int i=0;i<word.length();i++)
		{    

			if(current->child[(int)word[i]-(int)'a']==nullptr)
			{
				return false;
			}
			current = current->child[(int)word[i]-(int)'a'];
		}
        return current->isWord;
         
	}
};

int main()
{
	string word;
	Trie dic;
	fstream file("dict.dat");
	while(file>>word)
	{
		dic.loadWord(word);
	}
	file.close();
	cout<<"successful load the dictionary!"<<endl;
	cout<<"Please enter the word you want to find";
	for(int i=0;i<5;i++){
		cin>>word;
 
     if(dic.search(word))
     {
    	cout<<"found it!";
     }else{
    	cout<<"not in the dictionary!";
     }
    }
	return 0;
}
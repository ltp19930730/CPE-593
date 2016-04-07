#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Node{
public:
    string key;
    string value;
    Node* next;
    Node(string _key,string _value,Node* _next){
        key = _key;
        value = _value;
        next = _next;
    }
    Node(){
        key = "";
        value = "";
        next = nullptr;
    }
};
class Hashmap{
private:
	
	int size;
	int threshold;

	size_t hash(const string& s) const {
        std::hash<string> hash_fn;
        size_t h = hash_fn(s);
        return h;
    }
    int indexForKey(const string& s)const{
        size_t h = hash(s);
        return h%capacity;
    }
public:
	Node** table;
	int capacity;
	Hashmap(int initialSize)
	{
	     capacity = initialSize;
        size = 0;
        threshold = capacity/2;
        table = new Node*[capacity];
        for (int i = 0; i < capacity; i++) {
            *(table+i)=nullptr;
        }
	}
	Hashmap():Hashmap(2){
    }

	~Hashmap()
	{
		for(int i =0;i<size;i++)
			delete table[i];
		delete [] table;
	}
	 void growCapacity(){
       //grow cap   
            capacity = capacity*2;
            threshold = capacity/2;
            Node** newTable = new Node*[capacity];
            for (int i = 0; i < capacity; i++) {
                *(newTable+i) = nullptr;
            }
            for (int i = 0; i < capacity/2; i++) {
                Node * e = *(table+i);
                for (;e!=nullptr ; e=e->next) {
                int newIdx = indexForKey (e->key);
                    *(newTable+newIdx) = new Node(e->key,e->value,*(newTable+newIdx));
                }
                
            }
            delete [] table;
            table = newTable;
            
        }
	void addDict(const string &key,const string &value){
        
        int index = indexForKey(key);
        Node * e = *(table + index);
        for (; e != nullptr; e = e->next) {
            if(e->key == key){
                e->value = value;
                return;
            }
        }
        *(table+index) = new Node(key,value,*(table+index));
        
        size++;
        if (size == threshold) {
            growCapacity();
        }
        
    }

   string searchIntable(const string &key) const{
        int idx = indexForKey(key);
        Node* e = *(table+idx);
        
        if (e == nullptr){
            return "";
        }
        
        for(;
            e != nullptr;
            e = e->next){
            if (e->key == key) {
                return e->value;
            }
        }
        return "";
    }
     bool containskey(string &key){
        return searchIntable(key) != "";
    }

};

int main()
{
	Hashmap map;
	ifstream in("dict.txt");
    ifstream file("hw8.dat");
	string str;

    while (in >> str) {
        map.addDict(str,"2");
    }

    while (file >> str) {
        cout << str + ":\t" << (map.containskey(str)? "ture":"false")<<endl;
    }
    int hist[12];
    for (int i= 0; i<12 ; i++) {
        hist[i] = 0;
    }
    for (int i = 0; i<map.capacity; i++) {
        Node * e = *(map.table +i);
        int num = 0;
        for (; e!= nullptr; e=e->next) {
            num++;
        }
        if(num >11) num = 11;
        hist[num]++;
    }
    for(int i = 1; i<12; i++){
        cout<< i<<"\t"<<hist[i]<<endl;
     }
    return 0;
	
}
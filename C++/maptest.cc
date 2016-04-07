#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;
int main()
{
	map<string,size_t> word_count;
	set<string> exclude = {"the","but","and","or","an"};
	string word;
	while(cin>>word)
	{
		if(exclude.find(word)==exclude.end())
		{
		  ++word_count[word];
		}
	}
	for(const auto &w: word_count)
	{
		cout<<w.first<<" occurs" <<w.second
		<<((w.second>1)?"times":"time")<<endl;
	}
} 
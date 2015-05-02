/*
try to use some special containers here

//map----dictionary

//set
*/
#include<iostream>
#include<map>
#include<string>
#include<set>
#include<vector>
using namespace std;
int main(int argc, char* argv[])
{
	string tword;
	map<string, int> words;
	words["vermeer"] = 1;
	
	int ia[10] = { 1, 3, 5, 8, 5, 3, 1, 5, 8, 1 };
	vector<int> vec(ia, ia + 10);
	set<int> iset(vec.begin(), vec.end());
	set<string> word_exclusion;
	while (cin >> tword)
	{
		if (word_exclusion.count(tword))
			continue;
		words[tword]++;
	}

}
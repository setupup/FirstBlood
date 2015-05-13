#include <iostream>
#include <string>
#include <cassert>

#include "trie.h"

using namespace std;
int main()
{
	trie<std::string> t;
	fstream output("DMV1.txt", ios_base::in|ios_base::app);

	
	/*t.insert("wargame",1,1);
	t.insert("wombat",2,2);
	t.insert("wolfram",3,3);
	t.insert("world",4,4);
	t.insert("work",5,5);*/
	ifstream input("short.txt");
	string temp;
	while (input >> temp)
	{
		t.generate_DMV(temp, output);
	}
	
	
	string dmv;
	output.seekg(0); //
	while (output >> dmv)
	{
		t.insert(dmv, 1, 1);
	}
	//t.printlist(t.complete("wo"));
	auto list = t.complete("pl");
	t.printlist(list);
	
	
	//assert(t.size() == 5);
	//assert(t.has("war") == false);
	//assert(t.has("wargame") == true);

	//auto candidates = t.complete("wo");
	//assert(candidates.size() == 4);

	//candidates = t.complete("warg");
	//assert(candidates.size() == 1);
	//assert(*candidates[0] == "wargame");

	std::cout << "All ok." << std::endl;
	return 0;
}

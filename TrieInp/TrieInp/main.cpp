#include <iostream>
#include <vector>
#include <string>
#include"Node.h"
#include"Leaf.h"
#include"Trie.h"
using namespace std;

int main()
{
	Trie* trie = new Trie();
	trie->addWord("Hello",1,1);
	trie->addWord("Balloon",2,2);
	trie->addWord("Ball",3,3);
	trie->addWord("Call", 4, 3);
	trie->addWord("Darkness", 4, 3);
	trie->print(trie->searchWord("Hello"));
	trie->print(trie->searchWord("Ball"));
	trie->print(trie->searchWord("Call"));
	trie->print(trie->searchWord("Darkness"));
	trie->print(trie->searchWord("Balloon"));
	trie->print(trie->searchWord("Polymorph"));

	

	delete trie;
}
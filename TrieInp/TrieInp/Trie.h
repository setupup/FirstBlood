#ifndef TRIE_H_
#define TRIE_H_
#include"Node.h"
#include"Leaf.h"
#include<iostream>
#include<string>
using namespace std;
class Trie
{
public:
	Trie();
	~Trie();
	void addWord(string s, double lat, double lon);
	Node* searchWord(string s);
	void deleteWord(string s);
	void print(Node* resu);
private:
	Node* root;
};
#endif


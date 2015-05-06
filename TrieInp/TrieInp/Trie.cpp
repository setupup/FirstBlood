#include "Trie.h"


Trie::Trie()
{
	root = new Node();
}


Trie::~Trie()
{
	//free memory
}
void Trie::print(Node* resu)
{
	if (resu)
	{
		Leaf* res = resu->leaf;
		cout << res->name << " " << res->lat << " " << res->lon << endl;
	}
	else{
		cout << "seems that this word doesnt exist." << endl;
	}
}
void Trie::addWord(string s, double lat, double lon)
{
	Node* current = root;
	if (s.length() == 0)
	{
		current->setWordMarker();
		return;
	}
	for (int i = 0; i < s.length(); i++)
	{
		Node* child = current->findChild(s[i]);
		if (child != NULL)
		{
			current = child;
		}
		else
		{
			Node* tmp = new Node();
			tmp->setContent(s[i]);
			current->appendChild(tmp);
			current = tmp;
		}
		if (i == s.length() - 1){

			current->setWordMarker();  //set it as true as its a leaf
			current->leaf = new Leaf(s, lat, lon);
		}
	}
}
Node* Trie::searchWord(string s)
{
	//search function
	Node* current = root;
	while (current != NULL)
	{
		for (int i = 0; i < s.length(); i++)
		{
			Node* tmp = current->findChild(s[i]);
			if (tmp == NULL)
				return NULL;
			current = tmp;
		}
		if (current->wordMarker()) //leaf
			return current;
		else //immediate
			return NULL; //return all the potential results
	}
	return current; //oversearch
}
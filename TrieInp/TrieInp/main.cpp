#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Leaf{
public:
	Leaf(){ //constructor
		name = " ";
		lat = 0;
		lon = 0;
	}
	Leaf(string n, double la, double lo){
		name = n;
		lat = la;
		lon = lo;
	}
	~Leaf(){ //destructor

	}
	string name;
	double lat;
	double lon;

};
class Node {  //Node defination //initial list
public:
	Node() { mContent = ' '; mMarker = false; }
	~Node(){}
	char content() { return mContent; }
	void setContent(char c){ mContent = c; }
	bool wordMarker(){ return mMarker; }
	void setWordMarker(){ mMarker = true; }  //immediate or leaf
	Node* findChild(char c);
	void appendChild(Node* child) { mChildren.push_back(child); }  //push an object into the vector(child)
	vector<Node*> children(){ return mChildren; }
	Leaf* leaf;
	vector<Node*> getthemall(Node* current);

	char mContent;
	bool mMarker;
	vector<Node*> mChildren;
	
};

class Trie {   //Trie defination 
public:
	Trie();
	~Trie();
	void addWord(string s,double lat,double lon);
	Node* searchWord(string s);
	void deleteWord(string s);
	void print(Node* resu);
private:
	Node* root;
};
Node* Node::findChild(char c)
{
	for (int i = 0; i < mChildren.size(); i++)
	{
		Node* tmp = mChildren.at(i);
		if (tmp->content() == c)
		{
			return tmp;
		}
	}
	return NULL;
}
vector<Node*> Node::getthemall(Node* current)
{
	vector<Node*> record;
	vector<Node*> arrayRes;
	arrayRes = current->mChildren;
	while (1)
	{
		int i = 0;
		if (arrayRes[i]->mMarker == true)
		{
			record.push_back(arrayRes[i]);
			i++;
		}
		/*
		else if (arrayRes[i]->mMarker==false)
		{
			if ()
			arrayRes.pop_back(arrayRes[i]);
		}
		else
		{
			break;
		}
		*/
		
	}
	


}
Trie::Trie()
{
	root = new Node();
}
Trie::~Trie(){
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
void Trie::addWord(string s,double lat,double lon)
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
			current->leaf = new Leaf(s,lat,lon);
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
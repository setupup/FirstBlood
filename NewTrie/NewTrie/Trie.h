// Simple trie data structure using STL. Based on code by Vivek Narayanan.
// - rlyeh, 2013 BOOST licensed ~~ listening to Baroness / March to the Sea.

#pragma once
#include<fstream>
#include <map>
#include <vector>
#include <string>
#include<iostream>
using namespace std;
template<typename T>
class trie
{
public:

	trie() : flag(false)
	{}

	bool has(const T &collection) const {
		for (const auto &it : children) //like the usage of foreach
		if (it.second.has(collection)) //recursive usage
			return true;
		return flag && collection == value ? true : false;
	}

	void insert(const T& collection,const double& first,const double& second) {
		trie *node = this;
		for (auto &c : collection) {
			auto found = node->children.find(c); //first part of children is a char second is a trie(subtree) children is a pair set pair<key,value>
			if (found == node->children.end()) //cannot find
				node->children[c] = trie(node->value + c); //root node orgin value is ''
			node = &(node->children[c]);
		}
		node->flag = true;
		node->d2[0]=first;
		node->d2[1]=second;
	}
	//list method list all the exist pointers
	std::vector<const T*> list() const {
		std::vector<const T*> results;

		if (flag)	
			results.push_back(&value);  //what is the address mean// explanation, as the results defination is pointer *
		//can learn from this
		for (const auto &it : children) {
			auto values = it.second.list(); //recursive from the subtree //is this really necessary
			//I prefer to write the it.second.list()  //explanation look at line 39
			for (const auto &value : values)
				results.push_back(value); //this value is also a pointer
		}

		return results;
	}
	//complete method traverse the rest trie node
	std::vector<const T *> complete(const T &prefix) const {
		const trie *node = this;
		int i = 0;
		for (auto &elem : prefix) {

			++i;

			const auto found = node->children.find(elem); //everytime the node changes, iterator
			const auto found1 = node->children.find('#');
			if (found == node->children.end()&&found1==node->children.end())
				return std::vector<const T *>();
			else if (found == node->children.end() && found1 != node->children.end())
			{
				node = &found1->second;
			}
			else if (found != node->children.end() && found1 == node->children.end())
			{
				node = &found->second;
			}
			else{
				const trie *node1 = &found->second;
				const trie *node2 = &found1->second;
				
				node1->complete(prefix.substr(i));
				node2->complete(prefix.substr(i));
			}
							
		}

		return node->list();  //print all the answers under the midway node
	}
	//return the list size
	void printlist(vector < const T*>& list)
	{
		for (const auto& it : list)
		{
			std::cout << *it << endl;
		}
	}
	unsigned size() const {
		return list().size();
	}
	void generate_DMV(const string& s,fstream& output,const int& threshold=1)
	{

		output << s << endl;
		for (int i = 0; i < s.length(); ++i)
		{
			string temp = s;
			temp[i] = '#';
			output << temp << endl;
		}
	}

protected:

	trie(const T& _value) : value(_value), flag(false)
	{}

	T value;
	bool flag; //represent whether its a leaf node
	double d2[2];
	std::map< typename T::value_type, trie > children;
};


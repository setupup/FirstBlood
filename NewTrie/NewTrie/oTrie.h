// Simple otrie data structure using STL. Based on code by Vivek Narayanan.
// - rlyeh, 2013 BOOST licensed ~~ listening to Baroness / March to the Sea.
#ifndef __oTrie_H__
#define __oTrie_H__
#include<fstream>
#include <map>
#include <vector>
#include <string>
#include<iostream>
using namespace std;
typedef struct mix_data{
	string value;
	double coordinate[2];
} Mixdata;
class otrie
{
public:
	otrie() : flag(false) {}
	bool has(const string &collection) const {
		for (const auto &it : children) //like the usage of foreach
		if (it.second.has(collection)) //recursive usage
			return true;
		return flag && collection == md_.value ? true : false;
	}

	void insert(const Mixdata& md) {
		otrie *node = this;
		for (auto &c : md.value) {
			if (c<'a' || c>'z')
				continue;
			auto found = node->children.find(c); //first part of children is a char second is a trie(subtree) children is a pair set pair<key,value>
			if (found == node->children.end()) //cannot find
				node->children[c] = otrie(node->md_.value + c); //root node orgin value is ''
			node = &(node->children[c]);
		}
		node->flag = true;
		node->md_.coordinate[0] = md.coordinate[0];
		node->md_.coordinate[1] = md.coordinate[1];
	}
	//list method list all the exist pointers
	vector<const Mixdata*> list() const {
		vector<const Mixdata*> results;
		if (flag)
			results.push_back(&md_);  //what is the address mean// explanation, as the results defination is pointer *
		//can learn from this
		for (const auto &it : children) {
			auto values = it.second.list(); //recursive from the subtree //is this really necessary
			//I prefer to write the it.second.list()  //explanation look at line 39
			for (const auto &value : values)
				results.push_back(value); //this value is also a pointer
		}
		return results;
	}
	vector<vector<const Mixdata*>> list(vector<double> cen) const {
		vector<vector<const Mixdata*>> results(4);
		if (flag) //exit
		{
			if (md_.coordinate[0]<cen[0]&&md_.coordinate[1]<cen[1])
				results[0].push_back(&md_);  //what is the address mean// explanation, as the results defination is pointer *
			if (md_.coordinate[0]>cen[0] && md_.coordinate[1] < cen[1])
				results[1].push_back(&md_);
			if (md_.coordinate[0]>cen[0] && md_.coordinate[1] > cen[1])
				results[2].push_back(&md_);
			if (md_.coordinate[0]<cen[0] && md_.coordinate[1] > cen[1])
				results[3].push_back(&md_);
		}
			
		//can learn from this
		for (const auto& it : children) {
			auto values = it.second.list(cen); //recursive from the subtree //is this really necessary
			//I prefer to write the it.second.list()  //explanation look at line 39
			for (const auto &value : values[0])
				results[0].push_back(value); 
			for (const auto &value : values[1])
				results[0].push_back(value);
			for (const auto &value : values[2])
				results[0].push_back(value);
			for (const auto &value : values[3])
				results[0].push_back(value);
		}
		return results;
	}
	//complete method traverse the rest otrie node
	vector<const Mixdata *> complete(const string &prefix) const {
		const otrie *node = this;
		for (auto &elem : prefix) {
			const auto found = node->children.find(elem); //everytime the node changes, iterator

			if (found == node->children.end())
				return vector<const Mixdata *>();
			else
				node = &(found->second);
		}
		return node->list();  //print all the answers under the midway node
	}
	//return the list size
	void printlist(vector < const Mixdata*>& list)
	{
		for (const auto& it : list)
		{
			cout << it->value << " " << it->coordinate[0] << " " << it->coordinate[1] << endl;
		}
	}
	unsigned size() const {
		return list().size();
	}
	void generate_DMV(const string& s, fstream& output, const int& threshold = 1)
	{
		output << s << endl;
		for (int i = 0; i < s.length(); ++i)
		{
			string temp = s;
			temp[i] = '#';
			output << temp << endl;
		}
	}
//protected:
	otrie(const string& md) : flag(false)
	{
		md_.value = md;
	}
	Mixdata md_;
	bool flag; //represent whether its a leaf node
	map< string::value_type, otrie > children;
};

#endif

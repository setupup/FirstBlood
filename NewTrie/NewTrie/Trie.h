// Simple trie data structure using STL. Based on code by Vivek Narayanan.
// 

#pragma once
#include<fstream>
#include <map>
#include <vector>
#include <string>
#include<iostream>
using namespace std;
typedef struct mix_data{
	string value;
	double coordinate[2];
}Mixdata;
typedef struct region_{
	double leftupper[2];
	double rightdown[2];
}Region;
class trie
{
public:

	trie() : flag(false)
	{}
	bool preprocess();

	bool has(const string &collection) const {
		for (const auto &it : children) //like the usage of foreach
		if (it.second.has(collection)) //recursive usage
			return true;
		return flag && collection == mixdata.value ? true : false;
	}
	void insertAll();

	//void insert(const string& collection) {
	//	trie *node = this;
	//	for (auto &c : collection) {
	//		auto found = node->children.find(c); //first part of children is a char second is a trie(subtree) children is a pair set pair<key,value>
	//		if (found == node->children.end()) //cannot find
	//			node->children[c] = trie(node->mixdata.value + c); //root node orgin value is ''
	//		node = &(node->children[c]);
	//	}
	//	node->flag = true;
	//}
	//void insert(const string& collection, const double& first, const double& second) { //parameter overload
	//	trie *node = this;
	//	for (auto &c : collection) {
	//		auto found = node->children.find(c); //first part of children is a char second is a trie(subtree) children is a pair set pair<key,value>
	//		if (found == node->children.end()) //cannot find
	//			node->children[c] = trie(node->mixdata.value + c); //root node orgin value is ''
	//		node = &(node->children[c]);
	//	}
	//	node->flag = true;
	//	node->mixdata.coordinate[0] = first;
	//	node->mixdata.coordinate[1] = second;
	//}
	vector<const Mixdata*> singleGeoQuery(vector<const Mixdata*>& data,double upleft[],double downright[]){
		vector<const Mixdata*> result;
		for (const auto& lt : data)
		{
			if ((*lt).coordinate[0]>upleft[0] && (*lt).coordinate[0]<downright[0] && (*lt).coordinate[1]<upleft[1] && (*lt).coordinate[0]>downright[1])
			{
				result.push_back(lt);
			}
			
		}
		return result;
	}
	//list method list all the exist pointers
	vector<const Mixdata*> list() const {
		std::vector<const Mixdata*> results;

		if (flag)	
			results.push_back(&mixdata);  //what is the address mean// explanation, as the results defination is pointer *
		//can learn from this
		for (const auto &it : children) {
			auto values = it.second.list(); //recursive from the subtree //is this really necessary
			//merge deepone into this layer
			//I prefer to write the it.second.list()  //explanation look at line 39
			for (const auto &mixdata : values)
				results.push_back(mixdata); //this value is also a pointer
		}

		return results;
	}
	//complete method traverse the rest trie node
	vector<const Mixdata *> complete(const string &prefix) const {
		const trie *node = this;
		int i = 0;
		for (auto &elem : prefix) {

			++i;

			const auto found = node->children.find(elem); //this find() on the map should be very effcient
			const auto found1 = node->children.find('#');
			if (found == node->children.end()&&found1==node->children.end())
				return std::vector<const Mixdata *>();
			else if (found == node->children.end() && found1 != node->children.end())
			{
				node = &(found1->second);
			}
			else if (found != node->children.end() && found1 == node->children.end())
			{
				node = &(found->second);
			}
			else{
				const trie *node1 = &found->second; //elem
				const trie *node2 = &found1->second; //#
				
				vector<const Mixdata*> temp1=node1->complete(prefix.substr(i));
				vector<const Mixdata*> temp2 = node2->complete(prefix.substr(i));
				//vector<const string*>::const_iterator end1 = temp1.end();
				vector<const Mixdata*>::const_iterator be2 = temp2.begin();
				vector<const Mixdata*>::const_iterator end2 = temp2.end();
				
				for (; be2 != end2; ++be2)
				{
					temp1.push_back(*be2);
				}
				return temp1;
			}
							
		}

		return node->list();  //print all the answers under the midway node
	}
	//return the list size
	void printlist(vector < const Mixdata*>& list)
	{
		for (const auto& it : list)
		{
			std::cout << (*it).value<<" "<<(*it).coordinate[0]<<","<<(*it).coordinate[1]  << endl;
		}
	}
	unsigned size() const {
		return list().size();
	}
	void generate_DMV(const string& s,double& first,double& second,fstream& output,const int& threshold=1)
	{

		output << s << ' '<<first<<' '<<second<<endl; //the first one string
		for (int i = 0; i < s.length(); ++i)
		{
			string temp = s;
			temp[i] = '#';
			output << temp << ' ' << first << ' ' << second << endl;
		}
	}

protected:

	trie(const string& _value,double lu[2],double rd[2]) : flag(false)
	{
		mixdata.value = _value;
		region.leftupper[0] = lu[0];
		region.leftupper[1] = lu[1];
		region.rightdown[0] = rd[0];
		region.rightdown[1] = rd[1];


	}

	Mixdata mixdata;
	bool flag; //represent whether its a leaf node
	Region region;
	
	multimap<string::value_type, trie > children;  //the first parameter should be char here
};


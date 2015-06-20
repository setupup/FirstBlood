// Simple trie data structure using STL. Based on code by Vivek Narayanan.
// 
#ifndef _TRIE_H
#define _TRIE_H
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "oTrie.h"
using namespace std;
const int M = 6;

typedef struct region_{
	double x;
	double y;
	double width;
	double height;
}Region;
class trie
{
public:
	vector<const Mixdata*> list() const {
		vector<const Mixdata*> results;
		if (flag)
		{
			for (auto& elem:mixdata)
				results.push_back(&elem);  //what is the address mean// explanation, as the results defination is pointer *
		}
		
		//can learn from this
		for (const auto &it : children) {
			auto values = it.second.list(); //recursive from the subtree //is this really necessary
			//I prefer to write the it.second.list()  //explanation look at line 39
			for (const auto &value : values)
				results.push_back(value); //this value is also a pointer
		}
		return results;
	}
	//trie() : flag(false){}
	//bool preprocess();

	//bool has(const string &collection) const {
	//	for (const auto &it : children) //like the usage of foreach
	//	if (it.second.has(collection)) //recursive usage
	//		return true;
	//	return flag && collection == mixdata.value ? true : false;
	//}
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
	vector<const Mixdata*> singleGeoQuery(vector<const Mixdata*>& list,Region rg){
		vector<const Mixdata*> result;
		for (const auto& it : list)
		{
			if ((*it).coordinate[0]>rg.x && (*it).coordinate[0]<rg.x+rg.width && (*it).coordinate[1]<rg.y+rg.height && (*it).coordinate[1]>rg.y)
			{
				result.push_back(it); 
			}
		}
		return result;
	}
	//list method list all the exist pointers
	
	//complete method traverse the rest trie node
	vector<const Mixdata *> complete(const string &prefix,const Region& rg)  {

		trie *node = this;
		if (prefix.length() == 0)
			return node->list();
		vector<const Mixdata*> total;
			const auto found = node->children.equal_range(prefix[0]); //this find() on the map should be very effcient
			
			if (found.first==found.second)
				return std::vector<const Mixdata *>();

			else 
			{
				for (auto it = found.first; it != found.second; ++it)
				{
					if (judge_rect(it->second.region, rg))
					{
						auto results= it->second.complete(prefix.substr(1),rg);
						for (auto& elem : results)
						{
							total.push_back(elem);
						}
					}
				}
				return total;
			}				
		
		//return node->list();  //print all the answers under the midway node
	}
	//return the list size
	void printlist(vector < const Mixdata*>& list)
	{
		for (const auto& it : list)
		{
			std::cout << (*it).value<<" "<<(*it).coordinate[0]<<","<<(*it).coordinate[1]  << endl;
		}
	}
	//unsigned size() const {
	//	return list().size();
	//}
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

	double max(vector<const Mixdata*> list,int para)
	{
		double max = list[0]->coordinate[para];
		for (auto elem : list)
		{
			if (elem->coordinate[para] > max)
				max = elem->coordinate[para];
		}
		return max;
	}
	double min(vector<const Mixdata*> list, int para)
	{
		double min = list[0]->coordinate[para];
		for (auto elem : list)
		{
			if (elem->coordinate[para] < min)
				min = elem->coordinate[para];
		}
		return min;
	}
	double average(vector<const Mixdata*> list, int para)
	{
		double total=0;
		for (auto elem : list)
		{
			total = total + elem->coordinate[para];
		}
		return total / list.size();
	}
	Region compute_the_MBR(vector<const Mixdata*> list)
	{
		Region rg;
		if (list.size() > 1)
		{
			double minlat = min(list, 0); //
			double minlong = min(list, 1); //
			double maxlat = max(list, 0);
			double maxlong = max(list, 1);
			double width = maxlong - minlong;
			double height = maxlat - minlat;
			rg.x = minlat;
			rg.y = minlong;
			rg.width = width;
			rg.height = height;
		}
		else
		{
			double minlat = list[0]->coordinate[0]-0.1;
			double minlong = list[0]->coordinate[0]-0.1;
			double maxlat = list[0]->coordinate[0]+0.1;
			double maxlong = list[0]->coordinate[0]+0.1;
			double width = maxlong - minlong;
			double height = maxlat - minlat;
			rg.x = minlat;
			rg.y = minlong;
			rg.width = width;
			rg.height = height;
		}
		return rg;
	}
	vector<double> compute_the_centroid_and_split(const vector<const Mixdata*> list)
	{
		double vertical = average(list, 0);
		double horizen = average(list, 1);
		vector<double> cen;
		cen.push_back(vertical);
		cen.push_back(horizen);
		return cen;
	}
	bool judge_rect(Region rg1, Region rg2)
	{
		double minx;
		double miny;
		double maxx;
		double maxy;
		minx=std::max(rg1.x, rg2.x);
		miny = std::max(rg1.y, rg2.y);
		maxx = std::min(rg1.x + rg1.width, rg2.x + rg2.width);
		maxy = std::min(rg1.y + rg1.height, rg2.y + rg2.height);
		if (minx > maxx || miny > maxy)
			return false;
		else
			return true;
	}
	void insert_all(otrie* otrie)
	{
		trie* node = this;
		for (auto child : otrie->children)
		{
			auto list=child.second.list();
			if (list.size() < M&&list.size()>0)
			{
				Region rg=compute_the_MBR(list);
				node->children.insert(make_pair(child.first,trie(&rg,node,list)));
				//cout << "can we come here?" << endl;
				//return;
			}
			else //include the case that size()==1
			{
				//vector<double> centroid;
				//divide into 4 areas
				vector<double> cen;
				Region rg = compute_the_MBR(list);
				cen=compute_the_centroid_and_split(list);
				/*centroid[0] = cen[0];
				centroid[1] = cen[1];
				Region rg1;
				rg1.x = rg.x;
				rg1.y = rg.y;
				rg1.width = centroid[0]-rg.x;
				rg1.height = centroid[1] - rg.y;
				Region rg2;
				rg2.x = centroid[0];
				rg2.y = rg.y;
				rg2.width = rg.x + rg.width - centroid[0];
				rg2.height = centroid[1] - rg.y;
				Region rg3;
				rg3.x = centroid[0];
				rg3.y = centroid[1];
				rg3.width = rg.x + rg.width - centroid[0];
				rg3.height = rg.y + rg.height - centroid[1];
				Region rg4;
				rg4.x = rg.x;
				rg4.y = centroid[2];
				rg4.width = centroid[0] - rg.x;
				rg4.height = rg.y + rg.height - centroid[1];*/

				auto results = child.second.list(cen);	
				if (results[0].size() != 0) //find an exact method
				{
					Region rg1 = compute_the_MBR(results[0]);
					if (judge_rect(rg1,region))
					{
						auto childx = node->children.insert(make_pair(child.first, trie(&rg1, node)));
						//filtering
						(childx->second).insert_all(&(child.second));
					}
				}
				if (results[1].size() != 0 )
				{
					Region rg2 = compute_the_MBR(results[1]);
					if (judge_rect(rg2, region))
					{
						//node->children.insert(make_pair(child.first, trie(&rg2, node)));
						auto childy = node->children.insert(make_pair(child.first, trie(&rg2, node)));
						(childy->second).insert_all(&(child.second));
					}			
				}
				if (results[2].size() != 0)
				{
					Region rg3 = compute_the_MBR(results[2]);
					if (judge_rect(rg3, region))
					{
						//node->children.insert(make_pair(child.first, trie(&rg3, node)));
						auto childj = node->children.insert(make_pair(child.first, trie(&rg3, node)));
						(childj->second).insert_all(&(child.second));
					}
				}
				if (results[3].size() != 0)
				{
					Region rg4 = compute_the_MBR(results[3]);
					if (judge_rect(rg4, region))
					{
						//node->children.insert(make_pair(child.first, trie(&rg4, node)));
						auto childk = node->children.insert(make_pair(child.first, trie(&rg4, node)));
						(childk->second).insert_all(&(child.second));
					}
				}
			}
		}
		return;
	}
//protected:

	trie()
	{
		flag = false;
		region.x = -90;
		region.y = -180;
		region.width = 180;
		region.height = 360;
	}
	trie(Region* rg,trie* parent) : flag(false) //intermidiate constructor
	{
		region.x = rg->x;
		region.y = rg->y;
		region.width = rg->width;
		region.height = rg->height;
		_parent = parent;
	}
	trie(Region* rg, trie* parent,vector<const Mixdata*> md) : flag(true)  //leaf constructor
	{
		region.x = rg->x;
		region.y = rg->y;
		region.width = rg->width;
		region.height = rg->height;
		_parent = parent;
		for (auto& elem : md) //just a reference
		{
			mixdata.push_back(*elem);
		}
	}
	vector<const Mixdata> mixdata;
	bool flag; //represent whether its a leaf node
	Region region;
	double centroid[2];
	trie* _parent;

	multimap<string::value_type, trie > children;  //the first parameter should be char here
	//when want to equal_range
};

#endif

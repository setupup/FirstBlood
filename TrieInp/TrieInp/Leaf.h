#ifndef LEAF_H_
#define LEAF_H_
#include<iostream>
using namespace std;
class Leaf{
public:
	Leaf() :name(" "), lat(0), lon() //simple assignment use this complex continue
	{}
	Leaf(string n, double la, double lo) :name(n), lat(la), lon(lo)
	{}
	~Leaf(){ //destructor

	}
	string name;
	double lat;
	double lon;
};
#endif

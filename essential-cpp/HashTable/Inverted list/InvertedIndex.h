#ifndef INVERTED_INDEX_H_
#define INVERTED_INDEX_H_
#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<set>
#include<vector>

using namespace std;

class InvertedIndex{
public:
	InvertedIndex(){}
	~InvertedIndex(){}
	bool scanInput(const string&);
	void printContent() const;

private:
	static map<string, set<int>> invertedIndex;
};
#endif
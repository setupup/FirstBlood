#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<set>

using namespace std;

class InvertedIndex{
public:
	InvertedIndex(){}
	~InvertedIndex(){}
	bool scanInput(ifstream&);
	void printContent() const;

private:
	static map<string, set<int>> invertedIndex;
};
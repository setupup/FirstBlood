#include"InvertedIndex.h"


//defination
map<string, set<int>> InvertedIndex::invertedIndex;

bool InvertedIndex::scanInput(const string& str)
{
	//using this to make parsing words easier.
	//is.skipws();
	ifstream ifs(str);
	string filename;
	vector<string> vec;
	int countfile=0;
	while (ifs >> filename)
	{
		vec.push_back(filename);
	}
	for (vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		ifstream input(*iter);
		string word;
		while (input >> word)
		{
			invertedIndex[word].insert(countfile);
		}
		++countfile;
	}
	return true;
	
}

void InvertedIndex::printContent() const
{
	map<string, set<int>>::const_iterator iter = invertedIndex.begin();
	map<string, set<int>>::const_iterator it_end = invertedIndex.end();
	for (; iter != it_end; ++iter)
	{
		set<int> setvalue = iter->second;
		
		cout << iter->first << ":";
		set<int>::const_iterator setiter;
		for (setiter = setvalue.begin(); setiter != setvalue.end(); ++setiter)
		{
			cout << *setiter << " ";
		}

		cout << endl;
			

	}
}
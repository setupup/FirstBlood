#include"InvertedIndex.h"


//defination
map<string, set<int>> InvertedIndex::invertedIndex;

bool InvertedIndex::scanInput(ifstream& is)
{
	//using this to make parsing words easier.
	//is.skipws();
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
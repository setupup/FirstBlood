#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct record
{
	int rid;
	int len;
	vector<int> tokenArray;
	int indexPrefixLength, probePrefixLength;
};

struct result
{
	int xid, yid;
	double sim;
};

struct index_entry
{
	int rec;
	int pos;
};

struct inverted_list
{
	int startingPosition;
	vector<index_entry> list;
};

struct Counter
{
	Counter() : count(0){}
	void increment() {
		++count;
	}
	int count;
};

class ppjoin {
	static const int INF = 1 << 24;
	static const double EPS = 1e-8;
	bool jaccard, cosine;
	double threshold;
	int maxDepth;
	int recordNum;
	int tokenNum;
	int maxWidowTokenFrequency;
	vector<record> joinRecord;
	vector<result> joinResult;
	vector<inverted_list> invertedList;
	vector<int> tokenFrequency;

	public:
		ppjoin() {
			jaccard = cosine = 0;
			maxDepth = 2;
			recordNum = 0;
			tokenNum = -1;
			maxWidowTokenFrequency = 1;
		}
		int ReadParameters(char*, char*);
		int ReadParameters(char*, char*, char*);
		void ReadData(char*);
		void CalcPrefix();
		void BuildIndex();
		void PerformJoin();
		void WriteResults();
		int SuffixFilter(vector<int>&, vector<int>&, int, int, int, int, int, int);
		int CountOverlap(vector<int>&, vector<int>&, int, int, int, int, int);
		int BinarySearch(vector<int>&, int, int, int);
		int GetMaxDepth();
};


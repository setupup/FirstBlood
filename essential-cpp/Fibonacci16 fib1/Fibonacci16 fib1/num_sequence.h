#include<iostream>
using namespace std;
template<int len,int beg_pos>
class num_sequence{
public:
	virtual ~num_sequence(){}
	int elem(int pos) const;
	const char* what_am_i() const;
	static int max_elems(){ return _max_elems; }
	ostream& print(ostream& os = cout) const;
protected:
	virtual void gen_elems(int pos) const = 0;
	bool check_integrity(int pos, int size) const;
	num_sequence(vector<int>* pe) :_pelems(pe){}
	static const int _max_elems = 1024;
	vector<int>* _pelems;
};
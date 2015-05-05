#include<iostream>
#include<vector>
using namespace std;
class num_sequence{
public:
	virtual ~num_sequence(){}
	//=0 pure virtual function
	int elem(int pos) const=0; //return the pos elem //no need to give here virtual
	virtual const char* what_am_i() const=0; //return a char* to represent the type
	virtual ostream& print(ostream& os = cout) const=0; // print all the elems
	static int max_elems(){ return 64; }; //return support max pos
	int length() const { return _length; }

protected:
	num_sequence(int len, int bp, vector<int>& re)
		:_length(len), _beg_pos(bp), _relems(re){}
	virtual void gen_elems(int pos) const=0;// generate all elems until pos
	bool check_intergrity(int pos,int size) const; //if pos is valid
	//const static int _max_elems = 1024;
	int _length;
	int _beg_pos;
	vector<int>& _relems;


};
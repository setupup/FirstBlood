#include"num_sequence.h"
#include<vector>
using namespace std;
class Fibonacci :public num_sequence {
public:
	Fibonacci(int len = 1, int beg_pos = 1); //should do the remain work
		
	
	//virtual int elem(int pos) const;
	virtual const char* what_am_i() const { return "Fibonacci"; }

	

protected:
	virtual void gen_elems(int pos) const;
	static vector<int> _elems;
};
#include"num_sequence.h"
using namespace std;
template<int length,int beg_pos=1>
class Fibonacci :public num_sequence<length, beg_pos>
{
public:
	Fibonacci() :num_sequence<length, beg_pos>(&_elems){}
protected:
	virtual void gen_elems(int pos) const;
	static vector<int> _elems;  //need the declaration
};
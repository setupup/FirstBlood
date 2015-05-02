#include<iostream>

using namespace std;
class LessThan
{
public:
	LessThan(int val) :_val(val){}
	int comp_val() const { return _val; }
	void comp_val(int nval){ _val = nval; }

	//does this really work?
	bool operator()(int value) const; //braket operator ()

private:
	int _val;
};
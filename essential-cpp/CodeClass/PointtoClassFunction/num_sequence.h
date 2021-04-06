#include<iostream>
#include<vector>
using namespace std;
class num_sequence{
public:
	typedef void(num_sequence::*PtrType)(int);

	void fibonacci(int);
	void pell(int);
	void lucas(int);
	void triangular(int);
	void square(int);
	void pentagonal(int);
	int elem(int);
private:
	PtrType _pmf; //pointer to member function
	vector<int>* _elem; //point to the current vector.
	static const int num_seq = 7;
	static PtrType func_tbl[num_seq];
	static vector<vector<int>> seq;
		
};
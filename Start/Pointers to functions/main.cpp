/* Some fundamental exercises
$time$
HU Sheng, Essential C++ Chapter 

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<int>* fibon_seq(int size);// return a complete seq within the size 
const vector<int>* lucas_seq(int size);
const vector<int>* pell_seq(int size);
const vector<int>* triang_seq(int size);
const vector<int>* square_seq(int size);
const vector<int>* pent_seq(int size);

bool fibon_elem(int pos, int& elem,
	const vector<int>* (*fptr)(int))//input a postion and return the exact number in the assigned elem
//in here pass the pointer of function in 
{
	const vector<int>* pseq = fptr(pos);//compute and init the sequence
	if (!fptr)
	{
		cout << "Error!!" << endl;
	}
	if (!pseq)
	{
		elem = 0;
		return false;
	}
	elem = (*pseq)[pos - 1];
	return true;
}
int main(int argc, char* argv[])
{
	int a = 0;
	fibon_elem(2, a, fibon_seq);//use the function name to invoke
}
#include"iterator_overflow.h"
#include<sstream>
#include<string>
using namespace std;
const char* iterator_overflow::
what() const
{
	ostringstream ex_msg;
	static string msg;

	ex_msg << "Internal error: current Index "
		<< _index << "exceeds maximum bound: "
		<< _max;
	msg = ex_msg.str();
	return msg.c_str();
}
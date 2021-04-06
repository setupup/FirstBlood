#include<iostream>
#include<string>
using namespace std;
template<typename Ostream>
class PrintIt
{
public:
	PrintIt(Ostream& os) :_os(os){}

	template<typename elemType>
	void print(const elemType& elem, char delimiter = '\n')
	{
		_os << elem << delimiter;
	}
private:
	Ostream& _os;

};
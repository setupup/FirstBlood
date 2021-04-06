#include<string>
#include<vector>
class Triangular_iterator;
using namespace std;
class Triangular{ //actually include the usage of declaration
public:
	//
	//let the users not know the true name of class
	//the friend scope
	friend int operator*(const Triangular_iterator& rhs); //use friend on the function declare
	friend int Triangular_iterator::operator*()const; 
	friend void Triangular_iterator::check_integrity()const;
	typedef Triangular_iterator iterator;
	Triangular_iterator begin() const
	{
		return Triangular_iterator(_beg_pos);

	}
	Triangular_iterator end() const
	{
		return Triangular_iterator(_beg_pos + _length);
	}
	Triangular();
	
	Triangular(int len, int beg_pos);
	Triangular(const Triangular& tri);
	static bool is_elem(int value);
	static void gen_elems_to_value(int value);
	static void gen_elements(int length);

private:
	int _length;  
	int _beg_pos; //begin position
	int _next; //next iterate target
	string _name;
	static vector<int> _elems;
	static const int _max_elems = 1024;
};
#include"header.h"
class Triangular_iterator
{
public:
	friend int operator*(const Triangular_iterator& rhs);
	//friend class Triangular;

	Triangular_iterator(int index) :_index(index - 1){}
	bool operator==(const Triangular_iterator&) const;
	bool operator!=(const Triangular_iterator&) const;
	int operator*() const;
	Triangular_iterator& operator++(); //++i
	Triangular_iterator operator++(int); //i++ //should have been empty
private:
	int _index; //locate the Triangular static elems index should use friend
	void check_integrity() const;
};
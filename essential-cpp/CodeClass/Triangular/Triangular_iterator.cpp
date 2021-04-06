#include"Triangular_iterator.h"
inline bool Triangular_iterator::
operator==(const Triangular_iterator& rhs) const
{
	return _index == rhs._index;
}
inline bool Triangular_iterator::
operator!=(const Triangular_iterator& rhs) const
{
	return !(*this == rhs); //object!=  param
}
inline int Triangular_iterator::
operator*() const
{
	check_integrity();
	return Triangular_iterator::_elems[_index];
}
inline void Triangular_iterator::
check_integrity() const
{
	if (_index >= Triangular::_max_elems)
		throw iterator_overflow();
	if (_index >= Triangular::_elems.size())
		Trianguar::gen_elements(_index + 1);
}
inline Triangular_iterator& Triangular_iterator::
operator++()
{
	++_index;
	check_integrity();
	return *this;
}
inline Triangular_iterator Triangular_iterator::
operator++(int)
{
	Triangular_iterator tmp = *this;
	++_index;
	check_integrity();
	return tmp;
}
#include"Stack.h"
bool Stack::full()
{
	return _stack.size() == _stack.max_size();
}
bool Stack::empty()
{
	return _stack.size()?true:false;
}
bool Stack::peek(string& elem)
{
	if (empty())
		return false;
	elem = _stack.back();
	return true;
}
bool Stack::push(const string& elem)
{
	if (full())
		return false;
	_stack.push_back(elem);
	return true;
}
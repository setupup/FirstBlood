/*
Generic Programming
4/21
after using iterator
we got to use some generic algorithm here
to make the function to support various generic types
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
bool less_than(int v1, int v2)
{
	return v1 < v2 ? true : false;
}
bool greater_than(int v1, int v2)
{
	return v1 > v2 ? true : false;
}
//vector<int> filter(const vector<int>& vec, int filter_value, bool(*pred)(int, int))
//{
//	vector<int> nvec;
//	for (int ix = 0; ix < vec.size(); ++ix)
//	{
//		//use pred to compare
//		//
//		if (pred(vec[ix], filter_value))
//			nvec.push_back(vec[ix]);
//	}
//	return nvec;
//}
vector<int> filter(const vector<int>& vec, int filter_value, less<int>& lt)
{
	vector<int> nvec;
	vector<int>::const_iterator iter = vec.begin();
	while ((iter = find_if(iter, vec.end(), bind2nd(lt, filter_value))) != vec.end())
	{
		nvec.push_back(*iter);
		iter++;
	}
	return nvec;
}
int main(int argc, char* argv[])
{
	vector<int> big_vec = { 1, 2, 3, 4, 5, 6, 7 };
	int value = 15;
	vector<int> lt_10 = filter(big_vec, value, less_than);
	
	//cout << big_vec.front() << endl;
	return 0;
}
/* Some fstream exercises
2015-4-17
HU Sheng, Essential C++ Chapter 2
Procedural programming
//pass parameter by value? by reference
*/
#include<iostream>
#include<vector>
using namespace std;
void dispaly(vector<int> vec)
{
	for (int ix = 0; ix < vec.size(); ++ix)
	{
		cout << vec[ix] << ' ';
		cout << endl;
	}
}
void swap(int& val1, int& val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}
void bubble_sort(vector<int> &vec)
{
	for (int ix = 0; ix < vec.size();  ++ix)
	{
		for (int jx = ix + 1; jx < vec.size(); ++jx)
		{
			if (vec[ix]>vec[jx])
				swap(vec[ix], vec[jx]);

		}
	}
}
int main(int argc, char* argv[])
{
	int ia[] = {8,34,3,13,1,21,5,2};//int array
	vector<int> vec(ia, ia + 8);

	cout << "vector before being sorted" << endl;
	dispaly(vec);

	cout << "vector after being sorted" << endl;
	bubble_sort(vec);//inplace written but failed
	dispaly(vec);
}
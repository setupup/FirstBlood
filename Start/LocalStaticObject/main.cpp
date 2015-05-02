/* Some fundamental exercises
$time$
HU Sheng, Essential C++ Chapter 

*/
#include <iostream>
#include<vector>
#include <string>
using namespace std;

template <typename T> // only adapt on the first function
void display_message(const string& msg, const vector<T>& vec)
{
	//use the by reference can reduce the unnecessary stack space consmption
	cout << msg<<endl;
	for (int ix = 0; ix < vec.size(); ++ix)
	{
		T temp = vec[ix];
		cout << temp << ' ';
	}
}


int main(int argc, char* argv[])
{
	//vetctor<string> vec;//usage is almost the same as the common function
	vector<int> vec;
	string msg;
	display_message(msg, vec); //automatically embed the type int into the template


	/*
	int a = 0;
	int& b = a;
	cout << a << " " << b << endl;
	*/

}
/* Some fundamental exercises
$time$
HU Sheng, Essential C++ Chapter 

*/

#include <iostream>
using namespace std;
char* f()
{
	return "String!!";
}
int main(int argc, char* argv[])
{
	const char*a=f();
	cout << a << endl;

}
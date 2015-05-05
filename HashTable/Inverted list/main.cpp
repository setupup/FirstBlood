/* Some fundamental exercises
$time$
HU Sheng, Essential C++ Chapter 

*/
#include"InvertedIndex.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream ifs("inputs");
	InvertedIndex invertedIndex;
	bool flag=invertedIndex.scanInput(ifs);
	if (flag)
		invertedIndex.printContent();
	else
		cout << "something is wrong with the system";

}
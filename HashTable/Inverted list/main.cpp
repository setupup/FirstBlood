/* Some fundamental exercises
$time$
HU Sheng, Essential C++ Chapter 

*/
#include"InvertedIndex.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	
	InvertedIndex invertedIndex;
	bool flag=invertedIndex.scanInput("inputs.txt");
	if (flag)
		invertedIndex.printContent();
	else
		cout << "something is wrong with the system";

}
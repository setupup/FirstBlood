/* Some fundamental exercises
$time$
HU Sheng, Essential C++ Chapter 

*/
//STL contains the map to utilize the hash_map
#include <iostream>
#include <functional> //used by hash
#include <string>
#include <hash_map>  //not recommand
#include <unordered_map> //recommand please read the document of this class

using namespace std;

int main(int argc, char* argv[])
{

	//string str = "Meet the new boss...";
	//hash<string> hash_fn; //function object
	//size_t str_hash = hash_fn(str);

	//cout << str_hash << endl;
	unordered_map<string, string> myhashmap;
	myhashmap["the beginning part"] = "Mr Tang want Mrs Qiu";
	myhashmap["the medium part"] = "the millionare's happy life";
	myhashmap["the ending part"] = "This is called the bottom line of the salary";
	if (myhashmap.find("the ending part") != myhashmap.end())
	{
		cout << "not the end" << endl;
	}
	else{
		cout << "end confirmed" << endl;
	}


}
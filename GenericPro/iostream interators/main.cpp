/*
Using the iostream iterators
//when need to process the text file content iteratorly use this .
*/

#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char* argv[])
{
	string word;
	vector<string> text;
	//when read/write the file just repalce below with the ifstream object and ofstream object
	istream_iterator<string> is(cin); //means the first connect with the input stream
	istream_iterator<string> eof; //means last
	copy(is, eof, back_inserter(text)); //use back_inserter(text) instead of text
	sort(text.begin(), text.end());
	ostream_iterator<string> os(cout, " ");
	copy(text.begin(), text.end(), os);
}
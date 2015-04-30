//#include"LibMat.h"
#include<string>
using namespace std;
class Book :public LibMat{
public:
	Book(const string& title, const string& author)
		:_title(title), _author(author){
		cout << "Book::Book(" << _title <<
			", " << _author << ") constructor\n";
	}
	virtual ~Book()
	{
		cout << "Book::Book() destructor\n";
	}
	virtual void print() const{ //override the def of LibMat
		cout << "Book::print() -- I am a Book object!\n"
			<< "My title is: " << _title << '\n'
			<< "My author is: " << _author << endl;
	}
	const string& title() const{ return _title; }
	const string& author() const{ return _author; }
protected:
	string _title;
	string _author;
};
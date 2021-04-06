#include"Book.h"
#include<iostream>
#include<string>
using namespace std;
class AudioBook :public Book{
public:
	AudioBook(const string& title,
		const string& author, const string& narrator)
		:Book(title, author), _narrator(narrator)//init list combined with the parent constructor to save codes
	{
		cout << "AudioBook::AudioBook(" << _title
			<< ", " << _author
			<< ", " << _narrator
			<< ") constructor\n" << endl;
	}
	~AudioBook()
	{
		cout << "AudioBook::~AudioBook() destructor!\n";
	}
	virtual void print() const {
		cout << "AudioBook::print() -- I am an AudioBook object\n"
			<< "My title is: " << _title << '\n'
			<< "My author is: " << _author << '\n'
			<< "My narrator is: " << _narrator << endl;
	}
	const string& narrator() const { return _narrator; } // access funciton
protected:
	string _narrator;
};
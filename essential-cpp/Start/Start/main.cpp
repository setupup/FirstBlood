#include<iostream>
#include<fstream> //file stream
#include<Windows.h>
#include<string>

/* Some fstream exercises
 2015-4-17
 HU Sheng, Essential C++ Chapter 1
*/
using namespace std;
int main(int argc, char* argv[])
{
	
	//ofstream outfile("seq_data.txt",ios_base::app);//io append model
	////the bool value of outfile represent whether this file is open sucessfully
	//if (!outfile)
	//	cerr << "Oops! Unable to save the session data!\n";
	//else
	//	//success open
	//	outfile << "MYNAME" << " " << "25years old this year"<<endl ;
	//string name;
	//string desc;
	//ifstream infile("seq_data.txt");
	//if (!infile)
	//{
	//}
	//else
	//{
	//	infile >> name >> desc;
	//}
	//cout << name << " " << desc << endl;
	////meanwhile
	fstream iofile("seq_data.txt", ios_base::out); //input and append model
	if (!iofile)
	{
	}
	else
	{
		iofile << "IS this tail?" << endl;
		iofile.seekp(2);//put the cursor in the first line of this textfile
		iofile << "IS this tail?" << endl;
	}
		

	/*
	int i;
	i = (1 == 1) ? 1000 : 2;
	cout << i << endl;
	//system("pause");
	cout << "leeboy" ;
	Sleep(5000);
	cout << endl;
	*/
	
	return 0;

}
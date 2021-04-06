#include"LibMat.h"
#include"AudioBook.h"
#include<iostream>
using namespace std;
void print(const LibMat& mat) //all the children is through the refer of base class
{
	cout << "in global print(): about to print mat.print()\n";
	//according to the mat object to decide which print should be run
	mat.print();
}

//void loan_check_in(LibMat& mat)
//{
//	//mat represents one derived class object e.g. Book,RentalBook
//	mat.check_in();
//	if (mat.is_late())
//		mat.assess_fine();
//	if (mat.waiting_list())
//		mat.notify_available();
//}
int main()
{
	cout << "\n" << "Creating a AudioBook object to print()\n";
	//LibMat libmat;// constructor
	AudioBook ab("Mason and Dixon", "Thomas Pynchon", "Edwin Leonard");
		
	print(ab);  //Libmat& object

	//destructor
}
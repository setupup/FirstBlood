/* Some fundamental exercises
$time$
HU Sheng, Essential C++ Chapter 
mainly the introduction of class template
*/
#include <iostream>
#include"BinaryTree.h"
#include<string>
using namespace std;
template<typename elemType>
inline ostream&
operator<<(ostream& os, const BinaryTree<elemType>& bt)
{
	os << "Tree: " << endl;
	bt.print(os); //this function should be specified in the source code 
	return os;
}


int main(int argc, char* argv[])
{
	BinaryTree<string> bt;
	bt.insert("Piglet");
	bt.insert("Eeyore");
	bt.insert("Roo");
	bt.insert("Tigger");
	bt.insert("Chris");
	bt.insert("Pooh");
	bt.insert("Kanga");

	cout << "Preorder traversal: \n";
	bt.preorder();

	bt.remove("Piglet");
	cout << "\n\nPreorder traversal after Piglet removal: \n";
	bt.preorder();

	bt.remove("Eeyore");
	cout << "\n\nPreorder traversal after Eeyore removal: \n";
	bt.preorder();
	return 0;
}
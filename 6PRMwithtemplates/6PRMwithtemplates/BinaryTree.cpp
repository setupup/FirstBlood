#include"BinaryTree.h"

using namespace std;
template<typename elemType>
inline BinaryTree<elemType>::
BinaryTree() :_root(0)
{}

template<typename elemType>
inline BinaryTree<elemType>::
BinaryTree(const BinaryTree& rhs)
{
	copy(_root, rhs._root);
}
template<typename elemType>
inline BinaryTree<elemType>&  //with the common function, first write the return value 
BinaryTree<elemType>::
operator=(const BinaryTree& rhs)
{
	if (this != &rhs)
	{
		clear();
		copy(_root, rhs._root);
	}
	return *this; //when its the identical object, just return the original one
}

template<typename elemType>
inline void
BinaryTree<elemType>::
insert(const elemType& elem)
{
	if (!_root)
		_root = new BTnode<elemType>(elem);
	else
		_root->insert_value(elem);
}
template<typename elemType>
inline void
BinaryTree<elemType>::
remove(const elemType& elem)
{
	if (_root)
	{
		if (_root->_val == elem)
			remove_root(); //the root case is an exception
		else
			_root->remove_value(elem, _root);
	}
}
template<typename elemType>
void BinaryTree<elemType>::
remove_root()
{
	if (!_root) return;

	BTnode<elemType>* tmp = _root;  //tmp represent root now
	if (_root->_rchild) //if right node exists
	{
		_root = _root->_rchild; //right node

		//take the leftchild and insert it into the right's most underlying left leaf
		if (tmp->_lchild)
		{
			BTnode<elemType>* lc = tmp->_lchild;
			Btnode<elemType>* new lc = _root->_lchild; //right node's left child but newlc is a temp var
			if (!newlc)
				_root->_lchild = lc;

			else
				BTnode<elemType>::lchild_leaf(lc, newlc);
		}
	}
	else// the right sub doesnt exists
		_root = _root->_lchild;
	delete tmp; //as the _root has changed, but its created by new, and tmp represents the address of _root, it equal to delete _root
}
template<typename elemType>
void BinaryTree<elemType>::
clear(BTnode<elemType>* pt)
{
	if (pt)
	{
		clear(pt->_lchild);
		clear(pt->_rchild);
		delete pt;
	}
}
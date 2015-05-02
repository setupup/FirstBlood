#include"BTnode.h"
using namespace std;
template<typename valType>
BTnode<valType>::
BTnode(const valType& val) :_val(val)  //should use the init list as much as possible 
{
	_cnt = 1;
	_lchild = _rchild = 0;
}
template<typename valType>
void BTnode<valType>::
insert_value(const valType& val)
{
	if (val == _val)
	{
		_cnt++; return;
	}
	if (val < _val)
	{
		if (!_lchild)
			_lchild = new BTnode(val);
		else
			_lchild->insert_value(val);
	}
	else (val>_val)
	{
		if (!_rchild)
			_rchild = new BTnode(val);
		else
			_rchild->insert_value(val);
	}
}
template<typename valType>
void BTnode<valType>::
lchild_leaf(BTnode* leaf, BTnode* subtree)
{
	while (subtree->_lchild)
		subtree = subtree->_lchild; //continuously recursive this is the right subtree's left child
	subtree->_lchild = leaf;
}
template<typename valType>
void BTnode<valType>::
remove_value(const valType& val, BTnode*& prev)
{
	if (val < _val)
	{
		if (!_lchild)
			return; //not exsit in this binary tree //as the to find value is not certainly in this binary tree
		else
			_lchild->remove_value(val, _lchild); //invoke recursive and the second parameter is used in the finding case
	}
	else if (val>_val)
	{
		if (!_rchild) //not exist in this binary tree //the program is abort here
			return;
		else
			_rchild->remove_value(val, _rchild); //invoke recursive
	}
	else
	{
		//all above is to find the correct node
		//ok: find it that means val=_val
		if (_rchild) //current node's rchild
		{
			prev = _rchild;
			if (_lchild)
			if (!prev->_lchild)
				prev->_lchild = _lchild;
			else
				BTnode<valType>::lchild_leaf(_lchild, prev->_lchild);
		}
		else
			prev = _lchild;
		delete this;
	}
}
template<typename valType>
void BTnode<valType>::
preorder(BTnode* pt, ostream& os) const
{
	if (pt)
	{
		display_val(pt, os);
		if (pt->_lchild)
			preorder(pt->_lchild, os);
		if (pt->_rchild)
			preorder(pt->_rchild, os);
	}
}

template<typename valType>
void BTnode<valType>::
inorder(BTnode* pt, ostream& os) const
{
	if (pt)
	{
		
		if (pt->_lchild)
			inorder(pt->_lchild, os);
		display_val(pt, os);
		if (pt->_rchild)
			inorder(pt->_rchild, os);
	}
}

template<typename valType>
void BTnode<valType>::
postorder(BTnode* pt, ostream& os) const
{
	if (pt)
	{

		if (pt->_lchild)
			postorder(pt->_lchild, os);
		
		if (pt->_rchild)
			postorder(pt->_rchild, os);
		display_val(pt, os);
	}
}
template<typename valType>
void BTnode<valType>::
display_val(BTnode* pt, ostream& os) const
{
	os << pt->_val << " ";
}
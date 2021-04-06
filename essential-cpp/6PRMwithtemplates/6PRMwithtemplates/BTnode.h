#include<string>
#include<iostream>
using namespace std;

template<typename valType>
class BTnode{
public:
	BTnode(const valType& val);
	friend class BinaryTree<valType>;
	void insert_value(const valType& val);
	void remove_value(const valType& val,BTnode*& prev);
	
	static void lchild_leaf(BTnode* leaf, BTnode* subtree);

	void preorder(BTnode* pt, ostream& os) const; //dont change anything internal the object
	void inorder(BTnode* pt, ostream& os) const;
	void postorder(BTnode* pt, ostream& os) const;
	void display_val(BTnode* pt, ostream& os) const;



private:
	valType _val;
	int _cnt;
	BTnode* _lchild;
	BTnode* _rchild;
};
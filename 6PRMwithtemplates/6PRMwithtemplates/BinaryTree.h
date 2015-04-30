#include"BTnode.h"
template<typename elemType>
class BinaryTree{
public:
	BinaryTree();
	BinaryTree(const BinaryTree&);
	~BinaryTree();
	BinaryTree& operator=(const BinaryTree&);

	friend ostream& operator<<(ostream&, const BinaryTree<elemType>&);  //in order for the << to invoke print

	bool empty(){ return _root == 0; }
	void clear(){ if (_root){ clear(_root); _root = 0; } }
	void insert(const elemType& elem);
	void remove(const elemType& elem);
	//exception
	void remove_root();
	//void preorder
	//how to use the preorder function
	/*void preorder()
	{
		BTnode<elemType>* root;
		root->preorder(_root, cout);
	}*/
private:
	BTnode<elemType>* _root;
	void clear(BTnode<elemType>*);

	void copy(BTnode<elemType>* tar, BTnode<elemType>* src); //target and the source
};
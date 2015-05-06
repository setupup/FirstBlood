#include "Node.h"

Node* Node::findChild(char c)
{
	for (int i = 0; i < mChildren.size(); i++)
	{
		Node* tmp = mChildren.at(i);
		if (tmp->content() == c)
		{
			return tmp;
		}
	}
	return NULL;
}
vector<Node*> Node::getthemall(Node* current)
{
	vector<Node*> record;
	vector<Node*> arrayRes;
	arrayRes = current->mChildren;
	while (1)
	{
		int i = 0;
		if (arrayRes[i]->mMarker == true)
		{
			record.push_back(arrayRes[i]);
			i++;
		}
		/*
		else if (arrayRes[i]->mMarker==false)
		{
		if ()
		arrayRes.pop_back(arrayRes[i]);
		}
		else
		{
		break;
		}
		*/
	}
}


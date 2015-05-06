#pragma once
#include"Leaf.h"
#include<iostream>
#include<vector>

using namespace std;
class Node
{
public:
	Node() { mContent = ' '; mMarker = false; }
	~Node(){}
	char content() { return mContent; }
	void setContent(char c){ mContent = c; }
	bool wordMarker(){ return mMarker; }
	void setWordMarker(){ mMarker = true; }  //immediate or leaf
	Node* findChild(char c);
	void appendChild(Node* child) { mChildren.push_back(child); }  //push an object into the vector(child)
	vector<Node*> children(){ return mChildren; }
	Leaf* leaf;
	vector<Node*> getthemall(Node* current);

	char mContent;
	bool mMarker;
	vector<Node*> mChildren;
};


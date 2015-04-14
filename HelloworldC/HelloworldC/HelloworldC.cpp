// HelloworldC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAXKEYLEN 16
typedef struct KeysType
{
	char ch[MAXKEYLEN];
	int len;
}KeysType; //keyword type
typedef enum NodeKind{
	LEAF , BRANCH
}NodeKind;

//How to storethe Record? in memory, using memory address?
typedef struct Record{
	string details;  //keyword details
	double latitude;
	double longitude;
	Record(string s,double la,double longi){
		details = s;
		latitude = la;
		longitude = longi;

	}
} Record;

//
typedef struct TrieNode{
	NodeKind kind; //BRANCH or LEAF
	union {
		struct {
			KeysType K; 
			Record* infoptr;
		}lf;
		struct {
			TrieNode* ptr[27]; //first is $
			int num; //non null field #
		}bh;
	};
}TrieNode, * TrieTree;
//Searching process
Record* SearchTrie(TrieTree T, KeysType K){ //Trie Searech
	TrieTree p;
	int i;
	for (p = T,i = 0; p&&p->kind == BRANCH&&i < K.len;
		p = p->bh.ptr[ord(K.ch[i])], ++i);
	if (p&&p->kind == LEAF&&p->lf.K.ch == K.ch)
		return p->lf.infoptr;
	else return NULL;
}

int ord(char i) //invert char to num,$is0
{}
void init()//init a empty tree
{}
void insert(string s,double lat, double longi)
{//Reading content from file in the disk, How to store
	Record* rec = new Record(s, lat, longi); //when use new, must use pointer
	


}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


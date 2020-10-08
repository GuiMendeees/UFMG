#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct NodeT {
	int num;
	NodeT *esq;
	NodeT *dir;
};

struct BST {
	NodeT *root = nullptr;
	void insertNode(int num);
	void display ();

};

#endif

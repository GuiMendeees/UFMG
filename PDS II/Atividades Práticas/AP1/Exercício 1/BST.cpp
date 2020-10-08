#include "BST.hpp"

NodeT *createNode (int num){

	NodeT *aux = new NodeT;
	aux ->num = num;
	aux ->esq = nullptr;
	aux -> dir = nullptr;

	return aux;

}

void insertNodeHelper (NodeT *n, int num){
	if (num < n->num){
		if (n->esq == nullptr){
			n->esq = createNode(num);
		}

		else {
			insertNodeHelper (n->esq, num);
		}

	}

	else if (num > n->num){
		if (n->dir == nullptr){
			n->dir = createNode (num);
		}

		else {
			insertNodeHelper (n->dir, num);
		}
	}

}


void BST :: insertNode (int num){

	if (root != nullptr){
		insertNodeHelper (root, num);
	}

	else {
		root = createNode (num);
	}

}


void inorder (NodeT *n){

	if (n == nullptr)
		return;

	inorder(n->esq);
	cout << n->num<<" ";
	inorder(n->dir);
}

void BST :: display(){
	inorder (root);
	cout << endl;
}

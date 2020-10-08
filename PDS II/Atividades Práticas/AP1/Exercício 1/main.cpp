#include <iostream>
#include "BST.hpp"

int main (){

	BST bst;
    int n;
    
    while(cin >> n) {
        bst.insertNode (n);
	}
	
	bst.display ();

return 0;

}
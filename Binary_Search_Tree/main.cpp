#include <iostream>
#include "BinarySearchTree.h"
int main(){
    BST BSTree;

    BSTree.InsertBST(8,"龜仙人");
    BSTree.InsertBST(1000,"悟空");
    BSTree.InsertBST(2,"克林");
    BSTree.InsertBST(513,"比克");

    cout << "Inorder Traversal:" << '\n';
    BSTree.Inorder();
    cout << '\n';
    

    return 0;
}
#include <iostream>
#include "BinarySearchTree.h"
int main(){
    BST BSTree;

    BSTree.Insert(8,"龜仙人");
    BSTree.Insert(1000,"悟空");
    BSTree.Insert(2,"克林");
    BSTree.Insert(513,"比克");

    std::cout << "Inorder Traversal:" << '\n';
    BSTree.Inorder(BSTree.root);
    std::cout << '\n';
    

    return 0;
}
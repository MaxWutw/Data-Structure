#include <iostream>
#include "BinarySearchTree.h"
int main(){
    BST BSTree;

    BSTree.Insert(30, "a");
    BSTree.Insert(489, "b");
    BSTree.Insert(29, "c");
    BSTree.Insert(1000, "d");
    BSTree.Insert(573, "e");

    std::cout << "Inorder Traversal:" << '\n';
    BSTree.Inorder(BSTree.root);
    std::cout << '\n';

    Node *node = BSTree.Search(573);
    if(node == nullptr) std::cout << "Find no key " << node->get_key() << "in the Binary Search Tree." << '\n';
    else std::cout << "Find key " << node->get_key() << ". The data is " << node->get_data() << '\n';

    Node *node2 = BSTree.Search(901);
    if(node2 == nullptr) std::cout << "Find no key " << 901 << " in the Binary Search Tree." << '\n';
    else std::cout << "Find key " << node2->get_key() << ". The data is " << node2->get_data() << '\n';


    return 0;
}
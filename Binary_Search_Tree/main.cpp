#include <iostream>
#include "BinarySearchTree.hpp"
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

    Node *node = BSTree.Search(29);
    if(node == nullptr) std::cout << "Find no key in the Binary Search Tree.\n";
    else std::cout << "Find key " << node->get_key() << ". The data is " << node->get_data() << '\n';

    Node *node2 = BSTree.Search(901);
    if(node2 == nullptr) std::cout << "Find no key in the Binary Search Tree.\n";
    else std::cout << "Find key " << node2->get_key() << ". The data is " << node2->get_data() << '\n';

    std::cout << "After sort:" << '\n';
    BSTree.print_sort(BSTree.root);
    std::cout << '\n';

    BSTree.Delete_node(29);

    std::cout << "After Delete:" << '\n';
    BSTree.Inorder(BSTree.root);
    std::cout << '\n';

    Node *node3 = BSTree.Search(29);
    if(node3 == nullptr) std::cout << "Find no key in the Binary Search Tree.\n";
    else std::cout << "Find key " << node3->get_key() << ". The data is " << node3->get_data() << '\n';


    return 0;
}
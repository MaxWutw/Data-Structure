#include <iostream>
#include "BinaryTree.hpp"
using std::cout;
using std::cin;
using std::endl;
int main(){
    std::string seq = "A B C D E F x x x G H x I";
    BinaryTree BT(seq);
    BT.Inorder(BT.root);

    return 0;
}
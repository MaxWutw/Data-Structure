#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include <iostream>
#include <string>
#include <queue>

class TreeNode{
private:
    TreeNode *leftchild, *rightchild, *parent;
    int key;
    std::string data;
public:
    TreeNode():leftchild(nullptr), rightchild(nullptr), parent(nullptr), key(0), data(""){};
    TreeNode(int k, string inp_data):leftchild(nullptr), rightchild(nullptr), parent(nullptr), key(k), data(inp_data){};
};

#endif
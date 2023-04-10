#include <iostream>
#include <queue>
#include <sstream>
#ifndef BinarySearchTree_h
#define BinarySearchTree_h

class Node{
protected:
    Node *leftchild, *rightchild, *parent;
    std::string data;
    int key;
public:
    Node():leftchild(nullptr), rightchild(nullptr), parent(nullptr), data(""), key(0){};
    Node(int num, string d):leftchild(nullptr), rightchild(nullptr), parent(nullptr), data(d), key(num){};
};

class BST: public Node{
private:
    Node *root;
public:
    Node():root(0){};
    Node *Search(int k);
    void Insert(string data, int k);
    void Inorder();
};

Node* BST::Search(int k){
    Node *cur = root;
    while(cur != nullptr && cur->key != k){
        if(k < cur->leftchild)
            cur = cur->leftchild;
        else
            cur = cur->rightchild;
    }
    return cur;
}

#endif
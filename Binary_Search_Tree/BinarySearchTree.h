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
    Node(int num, std::string d):leftchild(nullptr), rightchild(nullptr), parent(nullptr), data(d), key(num){};
    friend class BST;
};

class BST: public Node{
private:
    Node *root;
public:
    BST():root(0){};
    Node *Search(int k);
    void Insert(int k, std::string d);
    void Inorder(Node *cur);
    void Preorder(Node *cur);
    void Postorder(Node *cur);
};

Node* BST::Search(int k){
    Node *cur = root;
    while(cur != nullptr && cur->key != k){
        if(k < cur->key)
            cur = cur->leftchild;
        else
            cur = cur->rightchild;
    }
    return cur;
}

void BST::Insert(int k, std::string d){
    Node *p = nullptr, *c = root;
    Node *cur = nullptr;
    Node *insert_node = new Node(k, d);
    while(cur != nullptr){
        p = cur;
        if(insert_node->key < cur->key)
            cur = cur->leftchild;
        else
            cur = cur->rightchild;
    }
    insert_node->parent = p;
    if(p == nullptr)
        this->root = insert_node;
    else if(insert_node->key < p->key)
        p->leftchild = insert_node;
    else
        p->rightchild = insert_node;
}

void BST::Inorder(Node *cur){ // LVR
    if(cur){
        Inorder(cur->leftchild);
        std::cout << cur->data << ' ';
        Inorder(cur->rightchild);
    }
}
void BST::Preorder(Node *cur){ // VLR
    if(cur){
        std::cout << cur->data << ' ';
        Preorder(cur->leftchild);
        Preorder(cur->rightchild);
    }
}

void BST::Postorder(Node *cur){ //LRV
    if(cur){
        Postorder(cur->leftchild);
        Postorder(cur->rightchild);
        std::cout << cur->data << ' ';
    }
}

#endif
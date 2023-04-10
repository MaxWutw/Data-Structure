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
    void Insert(string d, int k);
    void Inorder(Node *cur);
    void Preorder(Node *cur);
    void Postorder(Node *cur);
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

void BST::Insert(string d, int k){
    Node *p = nullptr, *c = root;
    Node *cur = nullptr;
    Node *insert_node = new Node(k, d);
    while(cur != nullptr){
        p = cur;
        if(insert_node->key < cur->key)
            cur = cur->leftchild;
        else
            cur = cur->rightchild
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
        cout << cur->data << ' ';
        Inorder(cur->rightchild);
    }
}
void BST::Preorder(Node *cur){ // VLR
    if(cur){
        cout << cur->data << ' ';
        Preorder(cur->leftchild);
        Preorder(cur->rightchild);
    }
}

void BST::Postorder(Node *cur){ //LRV
    if(cur){
        Postorder(cur->leftchild);
        Postorder(cur->rightchld);
        cout << cur->data << ' ';
    }
}

#endif
#include <iostream>
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
    int get_key(){return key;}
    std::string get_data(){return data;}
    friend class BST;
};

class BST{
public:
    Node *root;
    BST():root(nullptr){};
    Node *Search(int k);
    Node *Successor(Node *node);
    void Insert(int k, std::string d);
    void Inorder(Node *cur);
    void Preorder(Node *cur);
    void Postorder(Node *cur);
    void print_sort(Node *cur);
    void Delete_node(int delete_key);
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

Node* BST::Successor(Node *node){
    
}

void BST::Insert(int k, std::string d){
    Node *p = nullptr;
    Node *cur = nullptr;
    Node *insert_node = new Node(k, d);
    cur = root;
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

void BST::print_sort(Node *cur){ // Inorder Traversal is the sort of the data
    if(cur){
        print_sort(cur->leftchild);
        std::cout << cur->key << ' ';
        print_sort(cur->rightchild);
    }
}

void BST::Delete_node(int delete_key){
    Node *delete_node = BST.Search(delete_key);
    if(delete_node == nullptr){
        std::cout << "Data not found!" << '\n';
        return;
    }
    Node *del = nullptr, *delch = nullptr;

    if(delete_node->leftchild != nullptr || delete_node->rightchild)
        del = delete_node;
    else
        del = Successor(delete_node);
    if(del->leftchild != nullptr)
        delch = del->leftchild;
    else 
        delch = del->rightchild;

    if(delch != nullptr)
        delch->parent = del->parent;

    if(del->parent == nullptr) 
        this.root = delch;
    else if(del->parent->leftchild == del)
        del->parent->leftchild = delch;
    else
        del->parent->rightchild = delch;
    if(del != delete_node){
        delete_node->key = del->data;
        delete_node->data = del->data;
    }
    delete del;
}

#endif
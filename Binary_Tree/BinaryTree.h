#ifndef BinaryTree_h
#define BinaryTree_h
#include <iostream>
#include <sstream>
#include <queue>

class TreeNode{
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    char data;
public:
    TreeNode(){
        leftchild = nullptr;
        rightchild = nullptr;
        parent = nullptr;
        data = 'x';
    }
    TreeNode(char c){
        leftchild = nullptr;
        rightchild = nullptr;
        parent = nullptr;
        data = c;
    }
    friend class BinaryTree;
};

class BinaryTree{
private:
    
public:
    TreeNode *root;
    BinaryTree():root(nullptr){};
    BinaryTree(const std::string str);
    void LevelOrderConstuct(std::stringstream &ss);
    void LevelOrderInsert(char data);
    void Preorder(TreeNode *current); // VLR
    void Inorder(TreeNode *current); // LVR
    void Postorder(TreeNode *current); // LRV
};

BinaryTree::BinaryTree(const std::string str){
    std::stringstream ss;
    ss << str;
    root = new TreeNode;
    ss >> root->data;
    LevelOrderConstuct(ss);
}

void BinaryTree::LevelOrderConstuct(std::stringstream &ss){
    std::queue<TreeNode*> Q;
    TreeNode *current = root;
    char data = 'x';
    while(ss >> data){
        if(data >= 65 && data <= 90){
            TreeNode *new_node = new TreeNode(data);
            new_node->parent = current;
            current->leftchild = new_node;
            Q.push(new_node);
        }
        if(!(ss >> data)) break;
        if(data >= 65 && data <= 90){
            TreeNode *new_node = new TreeNode(data);
            new_node->parent = current;
            current->rightchild = new_node;
            Q.push(new_node);
        }
        current = Q.front();
        Q.pop();
    }
}

void BinaryTree::LevelOrderInsert(char data){
    std::queue<TreeNode*> Q;
    TreeNode *current = root;
    while(current){
        if(current->leftchild != nullptr){
            Q.push(current->leftchild);
        }
        else{
            TreeNode *new_node = new TreeNode(data);
            new_node->parent = current;
            current->leftchild = new_node;
            break;
        }
        if(current->rightchild != nullptr){
            Q.push(current->rightchild);
        }
        else{
            TreeNode *new_node = new TreeNode(data);
            new_node->parent = current;
            current->rightchild = new_node;
            break;
        }
        current = Q.front();
        Q.pop();
    }
}

void BinaryTree::Preorder(TreeNode *current){
    if(current){
        std::cout << current->data << ' ';
        Preorder(current->leftchild);
        Preorder(current->rightchild);
    }
}

void BinaryTree::Inorder(TreeNode *current){
    if(current){
        Inorder(current->leftchild);
        std::cout << current->data << ' ';
        Inorder(current->rightchild);
    }
}

void BinaryTree::Postorder(TreeNode *current){
    if(current){
        Postorder(current->leftchild);
        Postorder(current->rightchild);
        std::cout << current->data << ' ';
    }
}

#endif
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*right;
    Node*left;
    Node(int data){
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

class BST{
    public:
    Node*root;
    BST(){
        root = NULL;
    }

    Node* insert(Node*node, int data){
        if(node == NULL){
            node = new Node(data);
            return node;
        }
        if(data <= node->data){
            node->left = insert(node->left, data);
        }
        else{
            node->right = insert(node->right ,data);
        }
        return node;
    }
    Node* search(Node* node, int number){
        if(node == NULL || node->data == number){
            return node;
        }
        if(number < node->data){
            return search(node->left, number);
        }
        else{
            return search(node->right, number);
        }
    }
    int count(Node* node){
        if(node == NULL) return 0;
        return 1 + count(node->right) + count(node->left);
    }
};

int main(){ 
    BST tree;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        tree.root = tree.insert(tree.root, el);
    }
    int m;
    cin >> m;
    cout << tree.count(tree.search(tree.root, m));

    return 0;
}
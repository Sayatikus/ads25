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
    void preOrder(Node* node){
        if(node == NULL) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
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
    tree.preOrder(tree.search(tree.root, m));

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        right = NULL;
        left = NULL;
    }

};
class BST{ 
    public:
    Node* root;
    BST(){
        root = NULL;
    }
    Node* insert(Node* node, int data){
        if(node == NULL){
            node = new Node(data);
            return node;
        }
        if(data <= node->data){
            node->left = insert(node->left, data);
        }
        else{
            node->right = insert(node->right, data);
        }
        return node;
    }
    bool check(Node*node, string s){
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'L'){
                if(node->left == NULL){
                    return false;
                }
                node = node -> left;
            }else if(s[i] == 'R'){
                if(node->right == NULL){
                    return false;
                }
                node = node->right;
            }
        }
        return true;
    }
};


int main(){
    BST tree;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        tree.root = tree.insert(tree.root, el);
    }
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(tree.check(tree.root, s)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
}

    return 0;
}
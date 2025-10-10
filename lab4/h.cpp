#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;
    Node(int data) {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int data) {
        if (node == NULL) {
            return new Node(data);
        }
        if (data <= node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    Node* max_el(Node* node) {
        if (node->right == NULL) return node;
        return max_el(node->right);
    }

    void GST(Node* node, int &sum) {
        if (node == NULL) return;
        GST(node->right, sum);
        sum += node->data;
        cout << sum << " ";
        GST(node->left, sum);
    }
};

int main() {
    BST tree;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int el;
        cin >> el;
        tree.root = tree.insert(tree.root, el);
    }
    int sum = 0;
    tree.GST(tree.root, sum);
    return 0;
}
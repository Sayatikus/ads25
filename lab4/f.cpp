#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;
    Node(int data) {
        this->data = data;
        right = left = NULL;
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

    void count_tringles(Node* root) {
        if (root == NULL) return;
        queue<Node*> q;
        q.push(root);
        int count = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                Node* cur = q.front(); q.pop();
                if(cur->left && cur->right){
                    count++;
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        cout << count;
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

    tree.count_tringles(tree.root);

    return 0;
}
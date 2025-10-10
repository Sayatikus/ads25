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

    void levelsums(Node* root) {
        if (root == NULL) return;

        queue<Node*> q;
        q.push(root);
        vector<int> sums;

        while (!q.empty()) {
            int sz = q.size();
            int sum = 0;
            for (int i = 0; i < sz; i++) {
                Node* cur = q.front(); q.pop();
                sum += cur->data;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            sums.push_back(sum);
        }

        cout << sums.size() << endl;
        for (int i = 0; i < sums.size(); i++){
            cout << sums[i] << " ";
        } 
        cout << endl;
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

    tree.levelsums(tree.root);

    return 0;
}
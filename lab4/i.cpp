#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int multiplicity;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
        multiplicity = 1;
    }
};

struct BST {
    Node* root;
    BST() {
        root = NULL;
    }

    Node* getMin(Node* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    Node* add(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        } else if (root->data > data) {
            root->left = add(root->left, data);
        } else if (root->data < data) {
            root->right = add(root->right, data);
        } else {
            root->multiplicity++;
        }
        return root;
    }

    Node* deleteNode(Node* root, int data) {
        if (root == NULL) {
            return NULL;
        } else if (root->data > data) {
            root->left = deleteNode(root->left, data);
            return root;
        } else if (root->data < data) {
            root->right = deleteNode(root->right, data);
            return root;
        } else {
            if (root->multiplicity > 1) {
                root->multiplicity--;
                return root;
            }
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else {
                Node* temp = getMin(root->right);
                root->data = temp->data;
                root->multiplicity = temp->multiplicity;
                temp->multiplicity = 1;
                root->right = deleteNode(root->right, temp->data);
                return root;
            }
        }
    }

    Node* find(Node* root, int x) {
        if (root == NULL) {
            return NULL;
        } else if (root->data == x) {
            return root;
        } else if (root->data < x) {
            return find(root->right, x);
        } else {
            return find(root->left, x);
        }
    }

    int multiplicity(Node* root, int x) {
        Node* node = find(root, x);
        if (node == NULL) {
            return 0;
        } else {
            return node->multiplicity;
        }
    }
};

int main() {
    BST tree;
    int n;
    cin >> n;
    vector<int> results;

    for (int i = 0; i < n; i++) {
        int number;
        string command;
        cin >> command >> number;
        if (command == "insert") {
            tree.root = tree.add(tree.root, number);
        } else if (command == "delete") {
            tree.root = tree.deleteNode(tree.root, number);
        } else if (command == "cnt") {
            results.push_back(tree.multiplicity(tree.root, number));
        }
    }

    for (size_t i = 0; i < results.size(); i++) {
        cout << results[i];
        if (i + 1 < results.size()) cout << '\n';
    }

    return 0;
}
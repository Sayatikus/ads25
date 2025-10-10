#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int data){
        this->data = data;
        right = NULL;
        left = NULL;
    }

};  
int main(){
    int n;
    cin >> n;
    vector<Node*>vec(n + 1, NULL);
    for(int i = 1; i <= n; i++){
        vec[i] = new Node(i);
    }
    for(int i = 0; i < n - 1; i++){
        int x,y,z;
        cin >> x >> y >> z;
        if(z == 0)vec[x]->left = vec[y];
        else vec[x]->right = vec[y];
    }
    Node* root = vec[1];
    queue<Node*>q;
    q.push(root);
    int max_width = 0;
    while(!q.empty()){
        int level_size = q.size();
        max_width = max(max_width, level_size);
        for(int i = 0; i < level_size; i++){
            Node*current = q.front();
            q.pop();
            if(current->right != NULL) q.push(current -> right);
            if(current->left != NULL) q.push(current -> left);
    }
}
    cout << max_width;
    return 0;
}
#include <iostream>
using namespace std;

class Node{
    public:
    Node* next;
    int data;
    Node(int data){
        this->data = data;
        this->next = NULL;   
    }
};
class Insertion_of_Node{
    public:
    Node* Front;
    Node* Back;
    Insertion_of_Node(){
        Front = NULL;
        Back = NULL;
    }
    void push_back(int data){
        Node*node = new Node(data);
        if(Back == NULL){
            Front = Back = node;

        }else{
            Back->next = node;
            Back = node;
        }

    }
    void insert_el(int data, int m){
        Node*node = new Node(data);
        if(m == 0){
            node->next = Front;
            Front = node;
            return;
        }

        int count = 0;
        Node*temp = Front;
        while(count != m - 1){
            count++;
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;        


    }
    void print_all(){
        Node*temp = Front;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main(){
    Insertion_of_Node insert;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        insert.push_back(el);
    }
    int data,m;
    cin >> data >> m;
    insert.insert_el(data, m);
    insert.print_all();
    return 0;
}
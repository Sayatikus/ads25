#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    Node*next;
    string Data;
    Node(string Data){
        this->Data = Data;
        this->next = NULL;
    }
};
class LinkedList{
    public:
    Node*Front;
    Node*Back;
    int sz;
    LinkedList(){
        Front = NULL;
        Back = NULL;
        sz = 0;
    }
   void Check_and_Push_Front(string Data){
    if(Front == NULL){
        Node* node = new Node(Data);
        Front = Back = node;
        sz++;
        return;
    }
    if(Front->Data == Data){
        return;
    }
    Node* node = new Node(Data);
    node->next = Front;
    Front = node;
    sz++;
}
    void print_all(){
        Node* temp = Front;
        while(temp != NULL){
            cout << temp->Data << endl;
            temp = temp->next;
            }
        }
    void get_size(){
        cout << sz;
    }
};


int main(){
    LinkedList l;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string el;
        cin >> el;
        l.Check_and_Push_Front(el);
    }
    cout << "All in all: ";
    l.get_size();
    cout << endl;
    cout << "Students:" << endl;
    l.print_all();

}
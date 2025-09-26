#include <iostream>
#include <string>
using namespace std;

 class Node{
        public:
        Node* next;
        string data;
        Node(string data){
            this->data = data;
            this->next = NULL;
        }
};
    class Deque{
        public:
        Node* front;
        Node* back;
        int sz;
        Deque(){
            front = NULL;
            back = NULL;
            sz = 0;
        }
        void push_front(string data){
            Node*Element = new Node(data);
            if(front == NULL){
                front = back = Element;
            }
            else{
                Element->next = front;
                front = Element;
            }
            sz++;
        }
        void push_back(string data){
            Node*Element = new Node(data);
            if(back == NULL){
                front = back = Element;
            }
            else{
                back->next = Element;
                back = Element;
            }
            sz++;
        }
        void pop_front(){
            if(front == NULL) return;
            Node*temp = front;
            front = front->next;
            if(front == NULL) back = NULL;
            delete temp;
            sz--;
        }
        void pop_back(){
            if(front == NULL)return;
            if(back == front){
                delete back;
                back = front = NULL;
            }
            else{
                Node*temp = front;
                while(temp->next != back){
                    temp = temp->next;
                }
                delete back;
                back = temp;
                back->next = NULL;
            }
            sz--;
        }
        
        string get_front(){
            if (front == NULL) return "Empty";
            else return front->data;
        }
        string get_back(){
            if (back == NULL) return "Empty";
            else return back->data;
}   
        int get_size(){
            return sz;
        }
        void print_all(){
            Node* temp = front;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};


int main(){
    Deque d;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string el;
        cin >> el;
        d.push_back(el);
    }
    for(int i = 0; i < m; i++){
        d.push_back(d.get_front());
        d.pop_front();
    }
    d.print_all();
    return 0;
}
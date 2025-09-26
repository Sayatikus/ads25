#include <iostream>
using namespace std;

class Node {
    public:
    Node* next;
    int data;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

    class Fixing{
        public:
        Node* Back;
        Node* Front;
        int sz;
        Fixing(){
            Back = NULL;
            Front = NULL;
            sz = 0;
        }
        void push_back(int data){
            Node*node = new Node(data);
            if(Back == NULL){
                Back = Front = node;
            }else{
                Back->next = node;
                Back = node;
                Back->next = NULL;

            }
            sz++;
        }
        void delete_second_elements(){
            if(Front == NULL)return;
            Node* current = Front;
            Node*previous = NULL;
            int count = 1;
                while(current != NULL){
                    if(count % 2 == 0){
                        previous->next = current->next;
                        Node* Delete = current;
                        current = current->next;
                        delete Delete;

                    }
                    else if(count % 2 == 1){ 
                        previous = current;
                        current = current->next;
                        
                    }
                    count++;
}
        Back = previous;                
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
    Fixing f;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        f.push_back(el);
    }
    f.delete_second_elements();
    f.print_all();
    return 0;
}
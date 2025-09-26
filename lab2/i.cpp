#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    Node(string data){
        this->data = data;
        this->next = NULL;
    }
};
class Double_ll{
    public:
    Node*Front;
    Node*Back;
    Double_ll(){
        Front = NULL;
        Back = NULL;
    }
    string add_front(string data){
        Node* node = new Node(data); 
        if(Front == NULL){
            Front = Back = node;
        }
        else{
            node->next = Front;
            Front = node;
        }
        return "ok";
    }
    string add_back(string data){
        Node*node = new Node(data);
        if(Back == NULL){
            Front = Back = node;
        }
        else{
            Back->next = node;
            Back = node;
        }
        return "ok";
    }
    string erase_front(){
        if(Front == NULL) return "error";
        string book;
        Node* temp = Front;
        book = Front->data;
        Front = Front->next;
        delete temp;
        if (Front == NULL) Back = NULL;
        return book;
}
    string erase_back(){
        if(Back == NULL) return "error";
        string book = Back->data;
        if (Front == Back) {
            delete Back;
            Front = Back = NULL;
            return book;
        }
        Node*temp = Front;
        while(temp->next != Back){
            temp = temp->next;
        }
        
        delete Back;
        Back = temp;
        if (Back == NULL) Front = NULL;
        return book;
    }
    string front(){
        if(Front == NULL) return "error";
        return Front->data;
    }
    string back(){
        if(Back == NULL) return "error";
        return Back->data;
    }
    string clear(){
        Node* cur = Front;
        while(cur != NULL){
            Node* prev = cur;
            cur = cur->next;
            delete prev;
        }
        Front = Back = NULL;
        return "ok";
    }

};
int main(){
    Double_ll d;
    vector<string>vec;
    while(true){
        string command;
        cin >> command;
        if(command == "add_front"){
            string book;
            cin >> book;
            vec.push_back(d.add_front(book));
        }
        else if(command == "add_back"){
            string book;
            cin >> book;
            vec.push_back(d.add_back(book));
        }
        else if(command == "erase_front"){
            vec.push_back(d.erase_front());
        }
        else if(command == "erase_back"){
            vec.push_back(d.erase_back());
        }
        else if(command == "front"){
            vec.push_back(d.front());
        }
        else if(command == "back"){
            vec.push_back(d.back());
        }
        else if(command == "clear"){
            vec.push_back(d.clear());
        }
        else if(command == "exit"){
            vec.push_back("goodbye");
            break;
        }
    }
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
    return 0;       
}
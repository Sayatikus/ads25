#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if (p == 0 || head == nullptr){
        node->next = head;
        return node;
    }
    Node* temp = head;
    int count = 0;
    while(count < p - 1 && temp->next != nullptr){
        temp = temp->next;
        count++;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
}

 
Node* remove(Node* head, int p){
    if (head == nullptr) return nullptr;
    if (p == 0){
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }
    Node* temp = head;
    int count = 0;
    while(count < p - 1 && temp->next != nullptr){
        temp = temp->next;
        count++;
    }
    if (temp->next == nullptr) return head;
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    return head;
}

 
Node* replace(Node* head, int p1, int p2){
    if(p1 == p2)return head;
    if(p1 == 0){
        Node*r = head;
        head = head->next;
        Node* temp = head;
        int count = 0;
        while(count < p2 - 1){
            temp = temp->next;
            count++;
    }
        Node*right = temp->next;
        temp->next = r;
        r->next = right;
        return head;

    }
     if(p2 == 0){
        Node* temp = head;
        int count = 0;
        while(count < p1 - 1){
            temp = temp->next;
            count++;
    }
        Node*r = temp-> next;
        temp->next = temp->next->next;
        r->next = head;
        head = r;
        return head;
       

    }
    Node* temp = head;
    int count = 0;
    while(count < p1 - 1){
        temp = temp->next;
        count++;
    }
    Node* r = temp->next;
    Node*left = temp;
    Node*right = temp->next->next;
    left->next = right;
    Node*temp2 = head;
    int count2 = 0;
    while(count2 < p2 - 1){
        temp2 = temp2->next;
        count2++;
    }
    Node*right2 = temp2->next;
    temp2->next = r;
    r->next = right2;
    return head;

}
 
Node* reverse(Node* head){
    Node*prev = nullptr;
    Node* cur = head;
    while(cur != nullptr){
        Node*next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;

}
 
void print(Node* head){
    if(head == nullptr)return;
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}
 
Node* cyclic_left(Node* head, int x){
    if(x == 0)return head;
    int count = 1;
    Node* temp = head;
    while(count != x){
        temp = temp->next;
        count++;
    }
    Node*back = head;
    while(back->next != nullptr){
        back = back->next;
    }
    Node*Front = head;
    head = temp->next;
    temp->next = nullptr;
    back->next = Front;
    return head;
}

Node* cyclic_right(Node* head, int x){
    if (head == nullptr) return nullptr;

    int size = 1;
    Node* curr = head;
    while(curr->next != nullptr){
        curr = curr->next;
        size++;
    }

    x = x % size; 
    if (x == 0) return head;

    return cyclic_left(head, size - x);
}

 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}
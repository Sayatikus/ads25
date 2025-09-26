# include <iostream>
# include <algorithm>
# include <cassert>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
 
 
int findMaxSum(int n, Node *head) {
	int count = 0;
    int max = head->val;
    while(count != n){
        int sum = 0;
        Node *temp = head;
        if(count > 0){
            int c = 0;
            while(c != count){
                temp = temp->next;
                c++;
            }
        }
        while(temp != NULL){
            sum += temp->val;
            temp = temp->next;
            if(sum > max){
                max = sum;
            }
        }
        count++;
    }
    return max;
 
}
 
int main() {
  int n;
  cin >> n;
 
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cout << findMaxSum(n, head) << "\n";
  return 0;
}
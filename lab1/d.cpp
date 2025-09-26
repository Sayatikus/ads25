#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    char st[100000];
    int top = -1;

    for (char c : s) {
        if (top >= 0 && st[top] == c) {
            top--; 
        } else {
            st[++top] = c; 
        }
    }

    if (top == -1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
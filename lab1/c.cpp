#include <iostream>
#include <string>
using namespace std;

string process(string s) {
    char st[100000]; 
    int top = -1;   

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            if (top >= 0) top--; 
        } else {
            top++;
            st[top] = s[i]; 
        }
    }


    string res = "";
    for (int i = 0; i <= top; i++) {
        res += st[i];
    }
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string a = process(s1);
    string b = process(s2);

    if (a == b) cout << "Yes";
    else cout << "No";

    return 0;
}
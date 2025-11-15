#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi = prefix_function(s);

    int count = 0;
    for (int len = 1; 2 * len < n; len++) {
        bool ok = true;
        for (int i = 0; i < len; i++) {
            if (s[i] != s[len + i]) {
                ok = false;
                break;
            }
        }
        if (ok) count++;
    }

    cout << count;
    return 0;
}
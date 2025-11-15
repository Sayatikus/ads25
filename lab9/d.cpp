#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string to_lowercase(string s) {
    for (int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
    }  
    return s;
}

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int KMP(string text, string pattern) {
    string s = pattern + "#" + text;  
    vector<int> pi = prefix_function(s);
    if(pi.empty()){
        return 0;
    }
    return pi.back();
}

int main() {
    string P;
    int n;
    cin >> P >> n;
    
    vector<string> cities(n);
    for (int i = 0; i < n; i++)
        cin >> cities[i];

    vector<int> matches(n);
    int best = 0;

    for (int i = 0; i < n; i++) {
        matches[i] = KMP(to_lowercase(P), to_lowercase(cities[i]));
        best = max(best, matches[i]);
    }

    vector<string> result;
    for (int i = 0; i < n; i++) {
        if(best == 0) break;
        if (matches[i] == best)
            result.push_back(cities[i]);
    }

    cout << result.size() << endl;
    if(!result.empty()){
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << endl;
    }
    return 0;
}
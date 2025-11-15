#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;

    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

bool KMP(string text, string pattern){
    string s = pattern + "#" + text;
    int m = pattern.size();
    vector<int> pi = prefix_function(s);

    for(int i = m + 1; i < s.size(); i++){
        if(pi[i] == m){
            return true;
        }
    }
    return false;
}

int main(){
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    int repeats = (m + n - 1) / n; 
    string temp = "";
    for(int i = 0; i < repeats; i++)
        temp += a;

    if(KMP(temp, b)){
        cout << repeats;
    } else {
  
        temp += a;
        if(KMP(temp, b))
            cout << repeats + 1;
        else
            cout << -1;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int>pi(n);
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

int KMP(string text, string pattern){
    string s = pattern + '#' + text;
    
    int m = pattern.size();
    int n = s.size();
    
    vector<int> pi = prefix_function(s);
    int cnt = 0;
    for(int i = m + 1; i < n; i++){
        if(pi[i] == m){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    string pattern, text;
    int K; 
    cin >> pattern >> K >> text;
    if(KMP(text, pattern) >= K){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
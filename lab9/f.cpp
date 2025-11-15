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

vector<int> KMP(string pattern, string text){
    string s = pattern + "#" + text;
    int m = pattern.size();
    int n = s.size();
    vector<int>pi = prefix_function(s);
    vector<int>occ;
    for(int i = m + 1; i < n; i++){
        if(pi[i] == m){
            occ.push_back(i - m * 2);
        }
    }
    return occ;
}


int main(){
    string s1, s2;
    cin >> s1 >> s2;
    vector<int>occ = KMP(s2, s1);
    cout << occ.size() << endl;
    for(int i = 0; i < occ.size(); i++){
        cout << occ[i] + 1 << " ";
    }
    return 0;
}
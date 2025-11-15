#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

using ull = unsigned long long;
const ull P = 29;

ull get_hash(string s){
    ull h = 0;
    ull p_pow = 1;
    for(int i = 0; i < s.size(); i++){
        h += s[i] * p_pow;
        p_pow *= P;
    }
    return h;
}

vector<ull> get_pref_hash(string s){
    int n = s.size();
    vector<ull>h(n);
    h[0] = s[0];
    ull p_pow = P;
    for(int i = 1; i < n; i++){
        h[i] = s[i] * p_pow + h[i - 1];
        p_pow *= P;
    }
    return h;
}


int main(){
    string s;
    cin >> s;
    int n = s.size();
    unordered_set<ull>st;
    vector<ull>pref_h = get_pref_hash(s);
    vector<ull>pw(n);
    pw[0] = 1;
    for(int i = 1; i < n; i++){
        pw[i] = pw[i - 1] * P;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n - i; j++){
            ull hash = pref_h[j + i - 1];
            if(j > 0) hash -= pref_h[j - 1];
            hash *= pw[n - j - 1];
            st.insert(hash); 
        }
    }
    cout << st.size();
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
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
    int n;
    cin >> n;

    vector<ull>sh = get_pref_hash(s);

    int m = s.size();

    vector<ull>pw(m);
    pw[0] = 1;
    for(int i = 1; i < m; i++){
        pw[i] = pw[i - 1] * P;
    }

    for(int i = 0; i < n; i++){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        ull hash = sh[r];
        if(l > 0) hash -= sh[l - 1];
        int count = 0;
        int len = r - l + 1;
        for(int j = 0; j <= m - len; j++){
            ull h_sub = sh[j + len - 1];
            if(j > 0) h_sub -= sh[j - 1];
            if(h_sub * pw[l] == hash * pw[j]) count++;
        }
        cout << count << endl;
    }
    
    return 0;
}
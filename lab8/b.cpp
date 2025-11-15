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
    ull p_pow = P;
    vector<ull>h(n);
    h[0] = s[0];
    for(int i = 1; i < n; i++){
        h[i] = s[i] * p_pow + h[i - 1];
        p_pow *= P;
    }
    return h;
}

int main(){
    string s1, s2, t;
    cin >> s1 >> s2 >> t;
    
    int n1 = s1.size();
    int n2 = s2.size();
    int m = t.size();

    ull th = get_hash(t);

    vector<ull>s1h = get_pref_hash(s1);
    vector<ull>s2h = get_pref_hash(s2);
    int n = max(n1, n2);
    vector<ull> pw(n);
    

    vector<ull>occ1(n1);
    vector<ull>occ2(n2);

    pw[0] = 1;
    for(int i = 1; i < n; i++){
        pw[i] = pw[i - 1] * P;
    }

    for(int i = 0; i <= n1 - m; i++){
        ull h_sub = s1h[i + m - 1];
        if(i > 0) h_sub -= s1h[i - 1];
        if(h_sub == th * pw[i])occ1[i] = 1;
    }
      for(int i = 0; i <= n2 - m; i++){
        ull h_sub = s2h[i + m - 1];
        if(i > 0) h_sub -= s2h[i - 1];
        if(h_sub == th * pw[i])occ2[i] = 1;
    }

    int count = 0;
    int small = min(occ1.size(), occ2.size());
    for(int i = 0; i < small; i++){
        if(occ1[i] == 1 && occ2[i] == 1){
            count++;
        }
    }
    cout << count;
    return 0;
}
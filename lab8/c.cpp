#include <iostream>
#include <vector>
#include <string>
using namespace std;

using ull = unsigned long long;
const ull P = 29;

ull get_hash(string s){
    ull h = 0;
    ull p_pow = 1;
    for(int i = 0; i < s.length(); i++){
        h += s[i] * p_pow;
        p_pow *= P;
    }
    return h;
}

vector<ull> get_pref_h(string s){
    int n = s.size();
    vector<ull>h(n);
    h[0] = s[0];
    ull p_pow = P;
    for(int i = 1; i < n; i++){
        h[i] = h[i - 1] + s[i] * p_pow;
        p_pow *= P;
    }
    return h;
}

int main(){
    string s;
    int n;
    cin >> s >> n;
    vector<string>st;
    for(int i = 0; i < n; i++){
        string el;
        cin >> el;
        st.push_back(el);
    }
    ull hs = get_hash(s);

    vector<ull>hps = get_pref_h(s);

    int N = s.size();

    vector<ull>pw(N);
    pw[0] = 1;
    for(int i = 1; i < pw.size(); i++){
        pw[i] = pw[i - 1] * P;
    }

    vector<bool>cover(s.size(), false);
    
    for(int i = 0; i < st.size(); i++){
        int m = st[i].size();
        ull h = get_hash(st[i]);
        int N = s.size();        
        for(int j = 0; j <= s.size() - m; j++){
            ull h_sub = hps[j + m - 1];
            if(j > 0){
                h_sub -= hps[j - 1];
            }
            if(h_sub == h * pw[j]){
                for(int k = j; k < j + m; k++){
                    cover[k] = true;
                }
            }
        }
    }
    bool all_covered = true;
    for(int i = 0; i < cover.size(); i++){
        if(cover[i] == false){
            all_covered = false;
            break;
        }
    }
    if(all_covered){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    

    return 0;
}
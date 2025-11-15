#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//Hash
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

vector<ull> get_hash_pref(string s){
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
    while(true){
        string text;
        int number;
        cin >> number;
        if(number == 0)break;
        int count = 0;
        vector<string>h;
        while(count != number){
            string s;
            cin >> s;
            h.push_back(s);
            count++;
        }
        cin >> text;
        vector<pair<string, ull>>dom;
        vector<ull>text_pref_hash = get_hash_pref(text);
        int n = text.size();
        vector<ull>pw(n);
        pw[0] = 1;
        for(int i = 1; i < n; i++){
            pw[i] = pw[i - 1] * P;
        }
        for(int i = 0; i < h.size(); i++){
            int c = 0;
            int m = h[i].size();
            ull hash = get_hash(h[i]);
            for(int j = 0; j <= n - m; j++){
                ull h_sub = text_pref_hash[j + m - 1];
                if(j > 0) h_sub -=  text_pref_hash[j - 1];
                if(h_sub == hash * pw[j]) c++;
            }
            dom.push_back({h[i], c});
        }
        sort(dom.begin(), dom.end(),[](pair<string, ull>&a, pair<string, ull>&b){
            return a.second > b.second;
    });   
        ull max = dom[0].second;
        cout << max << endl;
        for(int i = 0; i < dom.size(); i++){
            if(dom[i].second == max){
                cout << dom[i].first << endl;
            }
            if(dom[i].second < max){
                break;
            }
        }
    }
    
    
    return 0;
}
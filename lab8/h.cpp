#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

using ull = unsigned long long;
const ull P = 29;

vector<ull> get_pref_hash(string s) {
    int n = s.size();
    vector<ull> h(n);
    h[0] = s[0];
    ull p_pow = P;
    for (int i = 1; i < n; i++) {
        h[i] = h[i - 1] * P + s[i];
    }
    return h;
}

ull get_hash(vector<ull> &h, int l, int r, vector<ull> &p) {
    if (l == 0) return h[r];
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    int min_len = vec[0].size();
    for (int i = 0; i < n; i++) if (vec[i].size() < min_len) min_len = vec[i].size();

    vector<vector<ull>> all_hashes(n);
    for (int i = 0; i < n; i++) all_hashes[i] = get_pref_hash(vec[i]);

    vector<ull> p_pow(min_len + 100);
    p_pow[0] = 1;
    for (int i = 1; i <= min_len; i++) p_pow[i] = p_pow[i - 1] * P;

    int l = 0, r = min_len;
    int ans_len = 0;
    ull ans_hash = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        unordered_set<ull> common;

        for (int i = 0; i + mid <= vec[0].size(); i++) {
            ull cur = get_hash(all_hashes[0], i, i + mid - 1, p_pow);
            common.insert(cur);
        }

        for (int k = 1; k < n; k++) {
            unordered_set<ull> cur_set;
            for (int i = 0; i + mid <= vec[k].size(); i++) {
                ull cur = get_hash(all_hashes[k], i, i + mid - 1, p_pow);
                if (common.count(cur)) cur_set.insert(cur);
            }
            common = move(cur_set);
            if (common.empty()) break;
        }

        if (!common.empty()) {
            ans_len = mid;
            ans_hash = *common.begin();
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    string answer = "";
    if (ans_len > 0) {
        vector<ull> &h = all_hashes[0];
        for (int i = 0; i + ans_len <= vec[0].size(); i++) {
            ull cur = get_hash(h, i, i + ans_len - 1, p_pow);
            if (cur == ans_hash) {
                answer = vec[0].substr(i, ans_len);
                break;
            }
        }
    }

    if (answer.size() > 0) cout << answer << endl;
    else cout << 0 << endl;

    return 0;
}
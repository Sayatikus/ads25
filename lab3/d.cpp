#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long count(const vector<int>& vec, int l, int r) {
    if (l > r) return 0; 
    
    long long left = 0, right = vec.size();
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (vec[mid] < l) left = mid + 1;
        else right = mid;
    }
    long long low = left; 

    left = 0; right = vec.size();

    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (vec[mid] <= r) left = mid + 1;
        else right = mid;
    }
    long long high = left;

    return high - low;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> vec;
    for (int i = 0; i < n; i++) {
        int el;
        cin >> el;
        vec.push_back(el);
    }
    sort(vec.begin(), vec.end());
    
    for (int i = 0; i < q; i++) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        long long L = count(vec, l1, r1);
        long long R = count(vec, l2, r2);

        long long mx = max(l1, l2);
        long long mn = min(r1, r2);
        long long d = count(vec, mx, mn);

        cout << L + R - d << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> result;

void Balance(int l, int r) {
    if (l > r) return; 
    int mid = l + (r - l) / 2;
    result.push_back(vec[mid]);
    Balance(l, mid - 1);
    Balance(mid + 1, r);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < pow(2, n) - 1; i++) {
        int el;
        cin >> el;
        vec.push_back(el);
    }
    sort(vec.begin(), vec.end());
    Balance(0, vec.size() - 1); 

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
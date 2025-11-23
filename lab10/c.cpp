#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<int> ans;

    while (b > a) {
        ans.push_back(b);
        if (b % 2 == 0) b /= 2;
        else b += 1;
    }

    while (b < a) {
        ans.push_back(b);
        b += 1;
    }

    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}
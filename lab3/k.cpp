#include <iostream>
#include <vector>
using namespace std;

long long check(vector<long long>& P, int k){
    int n = P.size();
    int length = n;

    for (int l = 0; l < n; l++) {
        int low = l+1, high = n-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long sum = P[mid] - P[l]; 
            if (sum >= k) {
                if ((mid - l) < length) {
                    length = mid - l;
                }
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return length;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    vector<long long> P;
    P.push_back(0); 
    for (int i = 1; i <= n; i++) {
        P.push_back(P[i-1] + vec[i-1]);
    }

    cout << check(P, k);
    return 0;
}
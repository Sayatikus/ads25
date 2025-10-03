#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int row, col;
    cin >> row >> col;
    vector<vector<int>> mesh(row, vector<int> (col));
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> mesh[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < row; j++) {
            for(int k = 0; k < col; k++) {
                if(arr[i] == mesh[j][k]) {
                    cout << j << " " << k;
                }
            }
        }
    }
}

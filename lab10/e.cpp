#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<vector<int>>a(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < q; i++){
        int x,y,z;
        cin >> x >> y >> z;
        x--;
        y--;
        z--;
        if(a[x][y] == 1 && a[x][z] == 1 && a[y][z] == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }

    return 0;
}
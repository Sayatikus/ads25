#include <iostream>
#include <vector>
using namespace std;


int find_element2(vector<int>& matrix, int x){
    int l = matrix.size() - 1;
    int r = 0;
    while(r <= l){
        int m = l + (r - l)/ 2;
        if(matrix[m] == x) return m;
        else if(matrix[m] < x) l = m - 1;
        else r = m + 1;
    }
    return -1;
}
int find_element(vector<int>& matrix, int x){
    int l = 0;
    int r = matrix.size() - 1;
    while(l <= r){
        int m = l + (r - l)/ 2;
        if(matrix[m] == x) return m;
        else if(matrix[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}


int main(){
    int t;
    cin >> t;
    vector<int>vec;
    for(int i = 0; i < t; i++){
        int el;
        cin >> el;
        vec.push_back(el);
    }
    int n,m;
    cin >> n >> m;
    vector<vector<int>>matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < vec.size() ; i++){
        bool found = false;
        for(int j = 0; j < matrix.size(); j++){
            int number = 0;
            if(j % 2 == 0){
                number = find_element2(matrix[j],vec[i]);
            }else{
                number = find_element(matrix[j],vec[i]);
            }
            if(number != -1){
                cout << j << " " << number << endl;
                found = true;
                break;
        }
    }
        if(!found){
            cout << -1 << endl;
        }
    }

    return 0;
}
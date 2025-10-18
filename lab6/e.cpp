#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>&arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int>L(n1), R(n2);

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
       if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }else{
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void MergeSort(vector<int>&arr, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>>matrix_new(n, vector<int>(m));
    for(int j = 0; j < m; j++){
        vector<int>vec;
        for(int i = 0; i < n; i++){
            vec.push_back(matrix[i][j]);
        }
        MergeSort(vec, 0, vec.size() - 1);
        for(int k = j; k < j + 1; k++){ 
            for(int i = 0; i < n; i++){
                matrix_new[i][j] = vec[n - 1 - i];
            }
       }

    }
    
            
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix_new[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
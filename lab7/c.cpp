#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int>L(n1), R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

}

void MergeSort(vector<int>&arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
}


}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> first_p;
    vector<int> second_p;

    for (int i = 0; i < n; i++){
        int el;
        cin >> el;
        first_p.push_back(el);
    }
    for (int i = 0; i < m; i++){
        int el;
        cin >> el;
        second_p.push_back(el);
    }

    vector<int> common;

    for (int i = 0; i < first_p.size(); i++) { 
        for (int j = 0; j < second_p.size(); j++) {
            if (second_p[j] == first_p[i]) {
                common.push_back(first_p[i]);
                first_p[i] = -1; 
                second_p[j] = -1;
                break;
            }
        }
    }
    MergeSort(common, 0, common.size() - 1);
    for (int i = 0; i < common.size(); i++)  cout << common[i] << " ";
       

    return 0;
}
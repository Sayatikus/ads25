#include <iostream>
#include <vector>
using namespace std;

bool Comparator(const pair<vector<int>, int>&a, const pair<vector<int>, int>&b){
    if(a.second != b.second){
        return a.second  > b.second;
    }
    return a.first < b.first;
}

void Merge(vector<pair<vector<int>, int>>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
     vector<pair<vector<int>, int>> L(n1), R(n2);

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){ 
    if(Comparator(L[i], R[j])){
        arr[k++] = L[i++];
        } 
    else{
        arr[k++] = R[j++];
        }
    }
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}

void MergeSort(vector<pair<vector<int>, int>>& arr, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int main(){
    int n, m; 
    cin >> n >> m;
    vector<pair<vector<int>,int>>vec;
    for(int i = 0; i < n; i++){
        int sum = 0;
        vector<int>num;
            for(int j = 0; j < m; j++){
            int el;
            cin >> el;
            sum += el;
            num.push_back(el);
        }
        vec.push_back({num ,sum});
    }
    MergeSort(vec, 0, vec.size() - 1);
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec[i].first.size(); j++){
            cout << vec[i].first[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
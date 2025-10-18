#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Merge(vector<char>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<char>L(n1), R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i];
    }
    for(int j = 0;j < n2; j++){
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
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void Merge_Sort(vector<char>&arr, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;
        Merge_Sort(arr, left, mid);
        Merge_Sort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int main(){ 
    string word;
    cin >> word;
    vector<char>letters;
    for(int i = 0; i < word.length(); i++){
        letters.push_back(word[i]);
    }
    Merge_Sort(letters, 0, letters.size() - 1);
    for(int i = 0; i < letters.size(); i++){
        cout << letters[i];
    }
    return 0;
}
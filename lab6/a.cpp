#include <iostream>
#include <vector>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
void Merge(vector<char>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<char> L(n1), R(n2);
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


void MergeSort(vector<char>& arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}
void Print(vector<char>& vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
    }
}

int main(){
    int n;
    cin >> n;
    vector<char>Vowel;
    vector<char>Consonants;
    for(int i = 0; i < n; i++){
        char l;
        cin >> l;
        if(isVowel(l)){
            Vowel.push_back(l);
        }
        else{
            Consonants.push_back(l);
        }
    }
    MergeSort(Vowel, 0, Vowel.size() - 1);
    MergeSort(Consonants, 0, Consonants.size() - 1);
    Print(Vowel);
    Print(Consonants);

    return 0;
}
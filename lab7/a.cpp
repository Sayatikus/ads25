#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Merge(vector<string>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string>L(n1), R(n2);

    for(int i = 0; i < n1; i++){
        L[i] = arr[left + i]; 
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if (L[i].size() <= R[j].size()){ 
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

void Merge_Sort(vector<string>&arr, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;

        Merge_Sort(arr, left, mid);
        Merge_Sort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int main(){
    int T;
    cin >> T;
    cin.ignore();
    for(int i = 0; i < T; i++){
        string s;
        getline(cin, s);
        s += ' ';
        vector<string>vec;
        string ss = "";
        for(int j = 0; j < s.length(); j++){
            
            if(s[j] == ' '){
                vec.push_back(ss);
                ss = "";
            }
            else{
                ss += s[j];
            }
        }
        Merge_Sort(vec, 0, vec.size() - 1);
        for(int k = 0; k < vec.size(); k++){
            cout << vec[k] << " ";
        }
        cout << endl;
    }
    return 0;
}
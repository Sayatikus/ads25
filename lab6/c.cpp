#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int>&arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void QuickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int p = Partition(arr, low, high);
        QuickSort(arr, low, p - 1);
        QuickSort(arr, p + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int>num;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        num.push_back(el);
    }
    QuickSort(num, 0, num.size() - 1);
    int d = num[1] - num[0];
    vector<pair<int, int>>p;
    for(int i = 0; i < num.size() - 1; i++){
        p.push_back(make_pair(i, num[i + 1] - num[i]));
        if(num[i + 1] - num[i] < d){
            d = num[i + 1] - num[i];

        }
    }
    for(int i = 0; i < p.size(); i++){
        if(p[i].second == d){
            cout << num[p[i].first] << " " << num[p[i].first + 1] << " ";
        }
    }
    return 0;;

}
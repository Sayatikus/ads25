#include <iostream>
#include <vector>
using namespace std;

bool check_number(vector<long long>&vec, int k){
    long long l = 0;
    long long r = vec.size() - 1;

    while(l <= r){
        long long mid = l + (r - l) / 2;
        if(vec[mid] == k)return true;
        else if(k < vec[mid]){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return false;
}


int main(){
    int n, k;
    cin >> n;
    vector<long long>vec;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        vec.push_back(el);
    }   
    cin >> k;
    if(check_number(vec, k)) cout << "Yes";
    else cout << "No";

    return 0;
}
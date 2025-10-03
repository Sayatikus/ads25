#include <iostream>
#include <vector>
using namespace std;


long long mpmn (vector<int>vec,int k){
    long long l = vec[0];
    long long r = 0;
    for(int i = 0; i < vec.size();i++){
        if(vec[i] > l){
            l = vec[i];
        }
        r += vec[i];
    }
    while(l <= r){
        long long mid = l + (r - l)/ 2;
        long long sum = 0;
        int count = 1;
        for(int i = 0; i < vec.size(); i++){
            if(sum + vec[i] <= mid){
                sum += vec[i];
            }else{
                sum = vec[i];
                count += 1;
            }
        }
        if(count <= k){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return l;
}


int main(){
    int n, k;
    cin >> n >> k;
    vector<int>vec;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        vec.push_back(el);
    }
    cout << mpmn(vec, k);
    return 0;
}
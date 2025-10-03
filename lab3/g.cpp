#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long find_capacity(vector<int>vec, int f){
    long long r = vec[0];
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] > r){
            r = vec[i];
        }
    }
    long long l = 1;
    long long answer = 0;
    while(l <= r){
        long long mid = l + (r - l) / 2;
        long long sum = 0;
        for(int i = 0; i < vec.size(); i++){
            sum += ceil((double)vec[i]/mid);
        }
        if(sum > f){
            l = mid + 1;
        }
        else if(sum <= f){
            answer = mid;
            r = mid - 1;
        }
    }
    return answer;
    
}

int main(){
    long long n, f;
    cin >> n >> f;
    vector<int>vec;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        vec.push_back(el);
    }
    cout << find_capacity(vec, f);
    return 0;
}
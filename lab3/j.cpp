#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long minimum_number_of_K(vector<long long>&vec, int h){
    long long r = vec[0];
    long long l = 1;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] > r){
            r = vec[i];
        }
    }
    while(l < r){
        long long mid = l + (r - l) / 2;
        int count = 0;
        for(int i = 0; i < vec.size(); i++){
            count += ceil(double(vec[i])/mid);
        }
        if(count <= h){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;

}


int main(){
    int n, h;
    cin >> n >> h;
    vector<long long>vec;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        vec.push_back(el);
    }
    cout << minimum_number_of_K(vec, h);



    return 0;
}
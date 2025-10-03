#include <iostream>
#include <vector>
using namespace std;

long long block_of_mistake(vector<long long>&P, int m, long long line){
    long long l = 0;
    long long r = m - 1;
    while(l < r){
        long long mid = l + (r - l)/2;
        if(P[mid] >= line){
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l + 1;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<long long>vec;
    vector<long long>P;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        vec.push_back(el);
    }
    for(int i = 0; i < vec.size(); i++){
        if(i == 0){
            P.push_back(vec[i]);
        }else{
            P.push_back(vec[i] + P[i - 1]);
        }
    }
    while(m--){ 
        long long line;
        cin >> line;
        cout << block_of_mistake(P, P.size(), line) << endl;
        }
    return 0;
}
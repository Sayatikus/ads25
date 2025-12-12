#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>vec;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        vec.push_back(el);
    }
    int min = vec[0];
    int index = 0;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] < min) {
            min = vec[i];
            index = i;
        }
    }
    int cost = 0;
    for(int i = 0; i < vec.size(); i++){
        if(i == index) continue;
        else cost += vec[i] + min;
    }
    cout << cost;
    
    return 0;
}
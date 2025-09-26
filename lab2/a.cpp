#include <iostream>
#include <vector>
#include <cmath>
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
    int k;
    cin >> k;
    int m = vec[0];
    int number = 0;
    for(int i = 1; i < vec.size(); i++){
        if(vec[i] == m){
            continue;
        }
        else if(k == vec[i]){
            number = i;
            break;
        }
        if(abs(k - vec[i]) < (abs(k - m)) ){
            if(abs(k - vec[i]) == (abs(k - m)) ){
                continue;
            }
            else{
                number = i;
                m = vec[i];
            }
        }
    }
    cout << number;
    return 0;
}
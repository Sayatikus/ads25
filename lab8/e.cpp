#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

using ull = unsigned long long;
const ull P = 29;

int main(){
    int n;
    cin >> n;
    vector<ull>hashes;
    for(int i = 0; i < n; i++){
        ull el;
        cin >> el;
        hashes.push_back(el);
    }
    for(int i = 0; i < hashes.size(); i++){
        if(i == 0){
            char c = char(97 + hashes[i]);
            cout << c;
        }
        else{
            ull hash = hashes[i] - hashes[i - 1];
            ull num = (97 * pow(2, i) + hash)/ pow(2, i);
            char c = char(num);
            cout << c;
        }
    }

    return 0;
}
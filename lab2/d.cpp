#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){ 
    int n;
    map<int,int>m;
    cin >> n;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        m[el]++;
    }
    vector<pair<int,int>>v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b){
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second > b.second;
});
    int max = v[0].second;
    for(int i = 0; i < v.size(); i++){
        if(v[i].second == max){
            cout << v[i].first << " ";
        }else{
            break;
        }
    }


    return 0;
}
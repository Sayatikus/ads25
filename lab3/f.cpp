#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long count_wins(vector<long long>& vec, int p) {
    
    int l = 0;
    int r = vec.size(); 
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (vec[mid] > p) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}




int main(){
    int n;
    cin >> n;
    vector<long long>vec;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        vec.push_back(el);
    }
    int R;
    cin >> R;
    sort(vec.begin(),vec.end());
    vector<long long> pr;
    for(int i = 0; i < vec.size(); i++){
        if(i == 0){
            pr.push_back(vec[i]);
        }
        else{
            pr.push_back(pr[i - 1] + vec[i]);
        }
    }
    for(int i = 0; i < R; i++){
        int p;
        cin >> p;
        if(count_wins(vec,p) == 0){
             cout << 0 << " " << 0 << endl;
        }
        else{
        cout << count_wins(vec,p) << " " << pr[count_wins(vec,p) - 1] << endl;
    }
    }
 
    return 0;
}
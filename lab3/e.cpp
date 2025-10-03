#include <iostream>
#include <vector>
using namespace std;


int check(int k, vector<int>vec){
    int l = 0;
    int r = vec[0];
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] > r){
            r = vec[i];
        }
    }
    int answer = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        int count = 0;
        for(int i = 0; i < vec.size(); i++){
            if(vec[i] <= mid){
                count++;
            }
        }
        if(count < k){
            l = mid + 1;
        }else if(count >= k){
            answer = mid;
            r = mid - 1;
        }

    }
    return answer;
}


int main(){
    int n,k;
    cin >> n >> k;
    vector<int>vec;
    for(int i = 0; i < n; i++){
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        vec.push_back(max(l2,r2));
    }
    cout << check(k, vec);

    return 0;
}
#include <iostream>
#include <deque>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int>vec;
    vector<int>vec2;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        vec.push_back(d);
        deque<int>dq;
        for(int j = d; j > 0; j--) {
            dq.push_front(j);
            for(int k = j; k > 0; k--){
                dq.push_front(dq.back());
                dq.pop_back();

           } 
        }
        for(int s = 0; s < dq.size(); s++){
            vec2.push_back(dq[s]);
        }
        dq.clear();
    }
    int i = 0;
    int j = 0;
    int counter = 0;
    while(i < vec2.size()){
        cout << vec2[i] << " ";
        counter++;
        if(counter == vec[j]){
            cout << endl;
            j++;
            counter = 0;
        }
        i++;
    }

    return 0;
}
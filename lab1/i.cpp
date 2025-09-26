#include <iostream>
#include <queue>
using namespace std;


int main(){
    int n;
    cin >> n;
    queue<int>K,S;
    for(int i = 0; i < n; i++){
        char el;
        cin >> el;
        if(el == 'K'){
            K.push(i);
        }
        else{
            S.push(i);
        }
    }
    while(!K.empty()&& !S.empty()){
        int i = K.front();
        int j = S.front();
        K.pop();
        S.pop();

        if (i < j) {
            K.push(i + n);
        } else {
            S.push(j + n);
        }
    }
    if (K.empty())
        cout << "SAKAYANAGI";
    else
        cout << "KATSURAGI";
    
    return 0;
}
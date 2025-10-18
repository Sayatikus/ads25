#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char>numbers;
    for(int i = 0; i < n; i++){
        char el;
        cin >> el;
        numbers.push_back(el);
    }
    char l;
    cin >> l;
    bool check = false;
    int index = 0;
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] == l){
            if(i + 1 < numbers.size()){
                check = true;
                index = i + 1;
        }
    }
}
    if(check == true){
        cout << numbers[index];
    }
    else{
        cout << numbers[0];
    }
    return 0;
}
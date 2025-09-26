#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

int main(){
    deque<int>dq;
    vector<string>vec;
    char s;

    while(true){
        int e;
        cin >> s;
        if(s == '!'){
            break;
        }
        if(s == '+' || s == '-'){
            int el;
            cin >> el;
            if(s == '+'){
                dq.push_front(el);
            }else if(s == '-'){
                dq.push_back(el);
            }
        }
        if(s == '*'){
            if(dq.empty()){
                vec.push_back("error");
            }else { 
                if(dq.size() == 1){  
                    vec.push_back(to_string(dq.front() + dq.back()));
                    dq.pop_back();
                }else{
                    vec.push_back(to_string(dq.front() + dq.back()));
                    dq.pop_back();
                    dq.pop_front();
                }
            }
        }
    }
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
    
    return 0;
}
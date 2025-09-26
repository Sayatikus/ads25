#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int a;
    cin >> a;
    vector <int> b(a);
    for (int i = 0; i < a; i++){
        cin >> b[i];
    }
    vector <int> c(a);
    stack <int> st;
    for (int i =0; i < a; i++){
        while( !st.empty() && st.top() > b[i]){
            st.pop();
        }
        if (st.empty()){
            c[i] = -1;
        }
        else{
            c[i] = st.top();
        }
        st.push(b[i]);

    }
    for (int i = 0; i < a; i++){
        cout << c[i] << " ";

    }
    return 0;
}
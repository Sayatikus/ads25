#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> B;
    queue<int> N;


    for (int i = 0; i < 5; i++) {
        int el;
        cin >> el;
        B.push(el);
    }

    for (int i = 0; i < 5; i++) {
        int el;
        cin >> el;
        N.push(el);
    }

    int count = 0;
    while (!B.empty() && !N.empty() && count < 1000000) {
        int a = B.front();
        B.pop();
        int b = N.front(); 
        N.pop(); 


        if ((a == 0 && b == 9) || (a > b && !(a == 9 && b == 0))) {
            B.push(a);
            B.push(b);
        }

        else {
            N.push(a);
            N.push(b);
        }

        count++;
    }

    if (B.empty() && count < 1000000) {
        cout << "Nursik " << count;
    } else if (N.empty() && count < 1000000) {
        cout << "Boris " << count;
    } else {
        cout << "blin nichya";
    }

    return 0;
}
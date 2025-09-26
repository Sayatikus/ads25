#include <iostream>
using namespace std;


bool isprime(int n){
    if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
    }
    return true;

}

int main(){
    int n;
    cin >> n;
    int i = 0;
    int count = 0;
    while(count != n){
        if(isprime(i)){
            count++;
        }
        i++;
    }
    int j = i - 1;
    int count2 = 0;
    int k = 0;
    while(count2 != j){
        if(isprime(k)){
            count2++;
        }
        k++;
    }
    cout << k - 1;
    return 0;
}
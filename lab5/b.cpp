#include <iostream>
#include <vector>
using namespace std;

class Max_Heap{
    public:
    vector<long long>a;
    int parent(int i){return (i - 1)/2;}
    int left(int i){return i * 2 + 1;}
    int right(int i){return i * 2 + 2;}
    
    void insert(long long el){
        a.push_back(el);
        int i = a.size() - 1;
        while(i > 0 && a[i] > a[parent(i)]){
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int biggest = i;
        if(l < a.size() && a[l] > a[biggest]){
            biggest = l;
        }
        if(r < a.size() && a[r] > a[biggest]){
            biggest = r;
        }
        if(biggest != i){
            swap(a[i], a[biggest]);
            heapify(biggest);
        }
    }
    long long extract_Max(){
        if (a.empty()) {
            return 0;
    }
        if(a.size() == 1){
            long long root = a[0];
            a.pop_back();
            return root;
        }
        long long root = a[0];
        a[0] = a.back();
        a.pop_back();
        heapify(0);
        return root;
    }
};

int main(){
    Max_Heap heap;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int el;
        cin >> el;
        heap.insert(el);
    }
    while(heap.a.size() > 1){
        long long y = heap.extract_Max();
        long long x = heap.extract_Max();
        if(x == y){
            continue;
        }else{
            int size = y - x;
            heap.insert(size);
        }
    }
    if(heap.a.empty()){
        cout << 0;
    }
    else{
        cout << heap.extract_Max();
    }
    return 0;   
}
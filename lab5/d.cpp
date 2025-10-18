#include <iostream>
#include <vector>
using namespace std;

class Min_Heap{
    public:
    vector<long long>a;

    int parent(int i){return (i - 1)/2;}
    int left(int i){return i * 2 + 1;}
    int right(int i){return i * 2 + 2;}

    void insert(long long el){
        a.push_back(el);
        long long i = a.size() - 1;
        while(i > 0 && a[i] < a[parent(i)]){
            swap(a[i],a[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i){
        long long l = left(i);
        long long r = right(i);
        long long smallest = i;
        if(l < a.size() && a[l] < a[smallest]){
            smallest = l;
        } 
        if(r < a.size() && a[r] < a[smallest]){
            smallest = r;
        } 
        if(smallest != i){
            swap(a[i], a[smallest]);
            heapify(smallest);
        }
    }
    long long extract_Min(){
        if(a.size() == 0){
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
    Min_Heap heap;
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        long long el;
        cin >> el;
        heap.insert(el);
    }
    long long count = 0;
    while(heap.a[0] < m && heap.a.size() > 1){
        long long a = heap.extract_Min();
        long long b = heap.extract_Min();
        long long new_num = a + 2 * b;
        heap.insert(new_num);
        count++;
    }
    if(heap.a[0] < m){
        cout << -1;
    }
    else{
        cout << count;
    }
    return 0;
}
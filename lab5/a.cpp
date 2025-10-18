#include <iostream>
#include <vector>
using namespace std;


class Min_Heap{
    public:
    vector<long long> a;
    int parent(int i){ return(i - 1)/2;}
    int left (int i){return i * 2 + 1;}
    int right(int i){return i * 2 + 2;}
    
    
    void insert(long long val){
        a.push_back(val);
        int i = a.size() - 1;

        while(i > 0 && a[i] < a[parent(i)]){
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
    void PrintHeap(){
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(r < a.size() && a[r] < a[smallest]){
            smallest = r;
        }
        
        if(l < a.size() && a[l] < a[smallest]){
            smallest = l;
        }
        if(smallest != i){
            swap(a[i], a[smallest]);
            heapify(smallest);
        }

    }
    long long extractMin(){
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
    long long n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long el;
        cin >> el;
        heap.insert(el);
    }
    long long sum = 0;
    while (heap.a.size() > 1) {
        long long x = heap.extractMin();
        long long y = heap.extractMin();

        long long s = x + y;
        sum += s;

        heap.insert(s);
}
    cout << sum;
    return 0;
}
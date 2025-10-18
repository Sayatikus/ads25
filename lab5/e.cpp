#include <iostream>
#include <vector>
#include <string>
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
    long long q, k;
    cin >> q >> k;
    for(int i = 0; i < q; i++){
        string el;
        cin >> el;
        if(el == "print"){
            if(heap.a.size() == 0){
                cout << 0 << endl;
            }
            else{
                long long sum = 0;
                for(int i = 0; i < heap.a.size(); i++){
                    sum += heap.a[i];
                }
                cout << sum << endl;
            }
        }
        else if(el == "insert"){
            long long el;
            cin >> el;
            if(heap.a.size() == k){
                int min = heap.extract_Min();
                if(min < el){
                    heap.insert(el);
                }else{
                    heap.insert(min);
                }
            }else{
                heap.insert(el);
            }
        }
    }
    return 0;
}
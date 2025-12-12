#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adjm(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adjm[i][j];
        }
    }
    const int INF = 1e9;
    vector<int> min_edge(n, INF);
    
    vector<bool> used(n, false);

    min_edge[0] = 0;

    int total_cost = 0;

    for(int i = 0; i < n; i++){
        int v = -1;

        for(int j = 0; j < n; j++){
            if(!used[j] && (v == -1 || min_edge[j] < min_edge[v])){
                v = j;
            }
        }
        used[v] = true;
        total_cost += min_edge[v];

        for(int to = 0; to < n; to++){
            if(v != to && !used[to]){
                min_edge[to] = min(min_edge[to], adjm[v][to]);
            }
        }
    }

    cout << total_cost;

    return 0;
}
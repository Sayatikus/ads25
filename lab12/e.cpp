#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int main() {
    int n;
    cin >> n;
    
    vector<vector<long long>> adj(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 100000) adj[i][j] = INF;
        }
    }
    
    vector<long long> dist(n, 0);
    vector<int> parent(n, -1);
    int cycle_vertex = -1;
    
    for (int iter = 0; iter < n; iter++) {
        cycle_vertex = -1;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (adj[u][v] < INF && dist[v] > dist[u] + adj[u][v]) {
                    dist[v] = dist[u] + adj[u][v];
                    parent[v] = u;
                    cycle_vertex = v;
                }
            }
        }
    }
    
    if (cycle_vertex == -1) {
        cout << "NO\n";
        return 0;
    }
    
    int v = cycle_vertex;
    for (int i = 0; i < n; i++) v = parent[v];
    
    vector<int> rev_cycle;
    int cur = v;
    do {
        rev_cycle.push_back(cur);
        cur = parent[cur];
    } while (cur != v);
    rev_cycle.push_back(v);
    
    reverse(rev_cycle.begin(), rev_cycle.end());
    
    int start_pos = -1;
    for (int i = 0; i < rev_cycle.size(); i++) {
        if (rev_cycle[i] == 2) { 
            start_pos = i;
            break;
        }
    }
    
    vector<int> final_cycle;
    if (start_pos != -1) {
        for (int i = start_pos; i < rev_cycle.size() - 1; i++) {
            final_cycle.push_back(rev_cycle[i]);
        }
        for (int i = 0; i <= start_pos; i++) {
            final_cycle.push_back(rev_cycle[i]);
        }
    } else {
        final_cycle = rev_cycle;
    }
    
    cout << "YES\n";
    cout << final_cycle.size() << "\n";
    for (int x : final_cycle) {
        cout << x + 1 << " ";
    }
    cout << "\n";
    
    return 0;
}
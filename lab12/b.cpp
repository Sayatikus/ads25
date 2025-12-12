#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector<long long> dijkstra(int start, int n, 
                          const vector<vector<pair<int, int>>>& adj) {
    vector<long long> dist(n + 1, INF);
    dist[start] = 0;
    
    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d != dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    
    int s, a, b, f;
    cin >> s >> a >> b >> f;
    
    vector<long long> dist_s = dijkstra(s, n, adj);
    vector<long long> dist_a = dijkstra(a, n, adj);
    vector<long long> dist_b = dijkstra(b, n, adj);
    
    long long sa = dist_s[a];
    long long sb = dist_s[b]; 
    long long ab = dist_a[b];
    long long af = dist_a[f];
    long long bf = dist_b[f];
    
    if (sa == INF || sb == INF || ab == INF || af == INF || bf == INF) {
        cout << -1 << endl;
        return 0;
    }
    
    long long way1 = sa + ab + bf; 
    long long way2 = sb + ab + af;
    
    long long answer = min(way1, way2);
    
    cout << answer << endl;
    
    return 0;
}
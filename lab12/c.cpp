#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> bfs(int start, int target, const vector<vector<int>>& adj, 
                const vector<bool>& blocked) {
    int n = adj.size();
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u == target) break;
        
        for (int v : adj[u]) {
            if (!blocked[v] && dist[v] == INF) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    
    vector<int> path;
    if (dist[target] != INF) {
        for (int v = target; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
    }
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> rail_adj(n + 1);
    vector<vector<bool>> rail_matrix(n + 1, vector<bool>(n + 1, false));
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        rail_adj[u].push_back(v);
        rail_adj[v].push_back(u);
        rail_matrix[u][v] = rail_matrix[v][u] = true;
    }
    
    vector<vector<int>> road_adj(n + 1);
    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (!rail_matrix[u][v]) {
                road_adj[u].push_back(v);
                road_adj[v].push_back(u);
            }
        }
    }
    
    int answer = INF;
    

    vector<int> olzhas_path = bfs(1, n, rail_adj, vector<bool>(n + 1, false));
    if (!olzhas_path.empty()) {
        vector<bool> blocked(n + 1, false);
    
        for (int i = 1; i < olzhas_path.size() - 1; i++) {
            blocked[olzhas_path[i]] = true;
        }
        
        vector<int> nugman_path = bfs(1, n, road_adj, blocked);
        if (!nugman_path.empty()) {
            answer = min(answer, max((int)olzhas_path.size() - 1, 
                                     (int)nugman_path.size() - 1));
        }
    }
    vector<int> nugman_path2 = bfs(1, n, road_adj, vector<bool>(n + 1, false));
    if (!nugman_path2.empty()) {
        vector<bool> blocked(n + 1, false);
        for (int i = 1; i < nugman_path2.size() - 1; i++) {
            blocked[nugman_path2[i]] = true;
        }
        
        vector<int> olzhas_path2 = bfs(1, n, rail_adj, blocked);
        if (!olzhas_path2.empty()) {
            answer = min(answer, max((int)nugman_path2.size() - 1,
                                     (int)olzhas_path2.size() - 1));
        }
    }
    
    if (answer == INF) {
        cout << -1 << endl;
    } else {
        cout << answer << endl;
    }
    
    return 0;
}
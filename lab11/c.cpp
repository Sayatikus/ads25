#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct DSU {
    vector<int> parent, rankv;
    DSU(int n) : parent(n+1), rankv(n+1, 0) {
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int v) {
        if(parent[v] == v) return v;
        parent[v] = find(parent[v]);
        return parent[v]; 
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(rankv[a] < rankv[b]) swap(a, b);
        parent[b] = a;
        if(rankv[a] == rankv[b]) rankv[a]++;
        return true;
    }
};

struct Edge {
    int a, b;
    long long w;
};

int main() {
    int n, m;
    cin >> n >> m;

    long long x, y;
    cin >> x >> y;

    vector<Edge> edges;

    for(int i = 0; i < m; i++) {
        string type;
        int a, b;
        long long c;
        cin >> type >> a >> b >> c;

        long long cost;
        
        if(type == "big") {
            cost = x * c;
        }
        else if(type == "small") {
            cost = y * c;
        }
        else {
            cost = min(x * c, y * c);
        }

        edges.push_back({a, b, cost});
    }

    sort(edges.begin(), edges.end(), [](const Edge &e1, const Edge &e2) {
        return e1.w < e2.w;
    });

    DSU dsu(n);
    long long answer = 0;
    int edges_used = 0;

    for(int i = 0; i < edges.size(); i++) {
        if(dsu.unite(edges[i].a, edges[i].b)) {
            answer += edges[i].w;
            edges_used++;
            if(edges_used == n - 1) break;
        }
    }

    cout << answer;
    return 0;
}
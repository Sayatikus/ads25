#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 200005;

vector<int> adj[MAXN];
bool used[MAXN];
int parent[MAXN];
int children[MAXN];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    int answer = 0;

    queue<int> q;

    for (int start = 1; start <= N; start++) {
        if (used[start]) continue;

        vector<int> comp;
        q.push(start);
        used[start] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            comp.push_back(v);

            for (int i = 0; i < adj[v].size(); i++) {
                int u = adj[v][i];
                if (!used[u]) {
                    used[u] = true;
                    q.push(u);
                }
            }
        }

        int root = comp[0];
        for (int i = 1; i < comp.size(); i++)
            if (comp[i] < root)
                root = comp[i];

        for (int i = 0; i < comp.size(); i++) {
            int v = comp[i];
            parent[v] = -1;
            children[v] = 0;
            used[v] = false; 
        }

        q.push(root);
        used[root] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int i = 0; i < adj[v].size(); i++) {
                int u = adj[v][i];
                if (!used[u]) {
                    used[u] = true;
                    parent[u] = v;
                    children[v]++; 
                    q.push(u);
                }
            }
        }
        
        answer++;

        for (int i = 0; i < comp.size(); i++) {
            int v = comp[i];
            if (v == root) continue;

            int p = parent[v];
            if (children[v] > children[p])
                answer++;
        }
    }

    cout << answer;

    return 0;
}
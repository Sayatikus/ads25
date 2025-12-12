#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<long long, long long>> cities(n);
    for(int i = 0; i < n; i++){
        cin >> cities[i].first >> cities[i].second;
    }
    const long long INF = 1e18;
    vector<long long> dist(n, INF);
    dist[0] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [current_dist, u] = pq.top();
        pq.pop();
        
        if(current_dist != dist[u]) continue;

        for(int v = 0; v < n; v++){
            if(v == u) continue;

             long long w = abs(cities[u].first - cities[v].first) + abs(cities[u].second - cities[v].second);

             long long condidate = max(dist[u], w);

             if(condidate < dist[v]){
                dist[v] = condidate;
                pq.push({dist[v], v});
             }
        }

       
    }

     cout << dist[n-1] << endl;
    
    return 0;
}
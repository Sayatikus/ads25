#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){ 
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }
    int s, e;
    cin >> s >> e;
    s--;
    e--;
    queue<int>q;
    vector<int>distance(n, -1);
    vector<bool>visited (n, false);

    distance[s] = 0;
    q.push(s);  

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for (int k = 0; k < n; k++) {
            if (adj[v][k] == 1 && distance[k] == -1) {
            distance[k] = distance[v] + 1;
            q.push(k);
            }
        }
    }
    cout << distance[e] << endl;
    
    return 0;
}
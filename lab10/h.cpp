#include <iostream>
using namespace std;

int n, m;
vector<string> grid;

int main() {
    cin >> n >> m;
    grid.resize(n);
    for(int i = 0; i < n; i++)
        cin >> grid[i];

    int islands = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '1' && !vis[i][j]) {
                islands++;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = true;

                while(!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < m &&
                           grid[nx][ny] == '1' && !vis[nx][ny]) {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    cout << islands;
}
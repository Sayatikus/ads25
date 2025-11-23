#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));

    int mushrooms = 0;
    int marios = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1) mushrooms++;
            else if(grid[i][j] == 2) marios++;
        }
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue<tuple<int, int, int>> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({i, j, 0});
            }
        }
    }

    int answer = 0;

    while(!q.empty()){
        auto [x, y, minute] = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(grid[nx][ny] == 1){
                grid[nx][ny] = 2;
                q.push({nx, ny, minute + 1});
                answer = max(answer, minute + 1);
            }
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                cout << -1;
                return 0;
            }
        }
    }

    cout << answer;
    return 0;
}
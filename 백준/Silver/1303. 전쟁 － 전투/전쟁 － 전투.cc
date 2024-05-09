#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<char>> battlefield;
vector<vector<bool>> visited;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs(int x, int y, char team) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int count = 0;

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        count++;

        for (int i = 0; i < 4; ++i) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (!visited[nx][ny] && battlefield[nx][ny] == team) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return count * count;
}

int main() {
    cin >> m >> n;
    battlefield = vector<vector<char>>(n, vector<char>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> battlefield[i][j];
        }
    }

    int white_power = 0, blue_power = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                if (battlefield[i][j] == 'W') {
                    white_power += bfs(i, j, 'W');
                } else if (battlefield[i][j] == 'B') {
                    blue_power += bfs(i, j, 'B');
                }
            }
        }
    }

    cout << white_power << " " << blue_power << endl;
    return 0;
}

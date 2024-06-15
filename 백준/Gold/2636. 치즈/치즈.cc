#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 100

int n, m;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> MAP[i][j];
        }
    }
}

void resetVisited() {
    memset(visited, false, sizeof(visited));
}

void bfsMarkExternalAir() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && MAP[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int meltCheese() {
    vector<pair<int, int>> toMelt;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (MAP[i][j] == 1) {
                int externalAirCount = 0;
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny]) {
                        externalAirCount++;
                    }
                }
                if (externalAirCount >= 1) {
                    toMelt.push_back({i, j});
                }
            }
        }
    }

    for (auto [x, y] : toMelt) {
        MAP[x][y] = 0;
    }

    return toMelt.size();
}

void solve() {
    int time = 0;
    int lastCheeseCount = 0;

    while (true) {
        resetVisited();
        bfsMarkExternalAir();

        int meltedCheese = meltCheese();
        if (meltedCheese == 0) {
            cout << time << endl;
            cout << lastCheeseCount << endl;
            return;
        }

        lastCheeseCount = meltedCheese;
        time++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}

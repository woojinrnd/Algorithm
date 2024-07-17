/*
1. 육지와 바다를 구분한다.
1-1. 육지와 육지를 구분한다. (인데스 부여)
1-2. 육지와 바다와 맞닿아 있는 칸을 구한다.(후보군)

2. 육지와 육지간 바다의 거리의 구한다.
2-1 후보군 * 후보군의 거리를 1:1 매칭하여 거리를 모두 구한다. (BFS)

3. 거리의 최솟값을 구한다.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int N[101][101];
bool vist[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point {
    int x, y;
};

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> N[i][j];
            if (N[i][j] == 1) N[i][j] = -1;
        }
    }
}

// 육지 라벨링
void Labeling_Land(int a, int b, int index) {
    queue<point> q;
    N[a][b] = index;
    vist[a][b] = true;
    q.push({a, b});

    while (!q.empty()) {
        point cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vist[nx][ny] || N[nx][ny] != -1) continue;
            vist[nx][ny] = true;
            N[nx][ny] = index;
            q.push({nx, ny});
        }
    }
}

// 섬들 사이의 최단 거리 찾기
int bfs(int num) {
    int res = 0;
    queue<point> q;
    memset(vist, 0, sizeof(vist));  // 방문 배열 초기화

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (N[i][j] == num) {
                vist[i][j] = true;
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            point cur = q.front();
            q.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (N[nx][ny] != 0 && N[nx][ny] != num) return res;  // 다른 섬을 만나면 현재 거리 반환
                else if (N[nx][ny] == 0 && !vist[nx][ny]) {
                    vist[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        res++;
    }

    return res;
}

void solution() {
    int land_label = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (N[i][j] == -1) {
                Labeling_Land(i, j, land_label);
                land_label++;
            }
        }
    }

    int answer = 9999;
    for (int i = 1; i < land_label; ++i) {
        answer = min(answer, bfs(i));
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();

    return 0;
}

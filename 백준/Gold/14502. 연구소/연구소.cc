#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int lab[10][10];     // 원본 연구소
int temp[10][10];    // 벽 세우고 BFS할 임시 배열
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct Point { int x, y; };
vector<Point> virus; // 바이러스 위치
vector<Point> A; // 빈 칸 위치
int res = 0;

// BFS로 바이러스 퍼트리기
void bfs() {
    int spread[10][10];
    memcpy(spread, temp, sizeof(temp));

    queue<Point> q;
    for (auto v : virus) q.push(v);

    while (!q.empty()) {
        Point cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (spread[nx][ny] == 0) {
                spread[nx][ny] = 2;
                q.push({ nx, ny });
            }
        }
    }

    int safe = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (spread[i][j] == 0) safe++;

    res = max(res, safe);
}

// DFS로 3개의 벽을 조합으로 선택
void dfs(int idx, int cnt) {
    if (cnt == 3) {
        memcpy(temp, lab, sizeof(lab));
        bfs();
        return;
    }
    for (int i = idx; i < A.size(); ++i) {
        Point p = A[i];
        lab[p.x][p.y] = 1; // 벽 설치
        dfs(i + 1, cnt + 1);
        lab[p.x][p.y] = 0; // 벽 제거
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) virus.push_back({ i, j });
            else if (lab[i][j] == 0) A.push_back({ i, j });
        }
    }

    dfs(0, 0);

    cout << res << "\n";
    return 0;
}

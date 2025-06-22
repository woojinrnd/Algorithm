#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int N[101][101];
int dist[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct point { 
    int x, y;
};
int cnt;
vector<int> each_area;

void input() {
    cin >> n >> m >> k;
    for (int i=0; i<k; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int new_y1 = n - y2;
        int new_y2 = n - y1;
        for (int i=new_y1; i<new_y2; ++i) {
            for (int j=x1; j<x2; ++j) {
                N[i][j] = 1;
            }
        }
    }
}

void solution() {
    //탐색영역 : N[i][j] = 0
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (N[i][j] == 1 || dist[i][j]!=0) continue;
            cnt++;
            int area = 0;
            queue<point> q;
            dist[i][j] = 1;
            q.push({i, j});
            while(!q.empty()) {
                point cur = q.front();
                q.pop();
                area++;

                for (int dir=0; dir<4; ++dir) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if (nx<0||nx>=n||ny<0||ny>=m) continue;
                    if (N[nx][ny]==1||dist[nx][ny]!=0) continue;
                    dist[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            each_area.push_back(area);
            // cout << area << ' ';
        }
    }
    sort(each_area.begin(), each_area.end());
    cout << cnt << '\n';
    for (int i : each_area) {
        cout << i << ' ';
    }
}

void show() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cout << N[i][j] << ' ';
        }
        cout << '\n';
    }
}

void solve() {
    input();
    solution();
    // show();
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
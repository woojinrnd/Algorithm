#include <iostream>
#include <queue>

using namespace std;

const int max_size = 102;

int h, n, m; //[h][n][m] = [높이][세로][가로]
int N[max_size][max_size][max_size];
int dist[max_size][max_size][max_size];
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
struct point {
	int x, y, z;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<point> Q;
	cin >> m >> n >> h;

	
	for (int k=0; k<h; ++k) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) { 
				cin >> N[k][i][j];
				// 익은 토마토 : BFS시작점 
				if (N[k][i][j] == 1) {
					Q.push({i,j,k});
				}
				// 익지 않은 토마토 : 아직 방문하지 않음
				// bfs 돌릴 탐색 구간 
				if (N[k][i][j] == 0) {
					dist[k][i][j] = -1;
				} 
				
			}
		}
	}
	while (!Q.empty()) {
		point cur = Q.front();
		Q.pop();
		for (int dir=0; dir<6;++dir) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			int nz = cur.z + dz[dir];
			if (nx<0||nx>=n||ny<0||ny>=m||nz<0||nz>=h) continue;
			if (dist[nz][nx][ny]>=0||N[nz][nx][ny]==-1) continue;
			dist[nz][nx][ny] = dist[cur.z][cur.x][cur.y] + 1;
			Q.push({nx, ny, nz});
		}
	}
	
    int ans = 0;
    for (int k=0; k<h; ++k) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (N[k][i][j] == 0 && dist[k][i][j] == -1) {
                    cout << -1;
                    return 0;
                }
                if (ans < dist[k][i][j]) ans = dist[k][i][j];
            }
        }
    }
    cout << ans;
	
	
	
	return 0;
}
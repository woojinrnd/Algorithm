#include <iostream>
#include <queue>

using namespace std;

const int max_sz= 1005;
int Tc;
int dist1[max_sz][max_sz]; // 불의 이동 시간
int dist2[max_sz][max_sz]; // 사람의 이동 시간

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct point {
    int x, y;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> Tc;
    while(Tc--) {
        queue<point> Q1; // 불의 위치
        queue<point> Q2; // 사람의 위치
        int w=0;
        int h=0;
        cin >> w >> h;
        
        // 초기화: 방문 여부 및 이동 시간
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                dist1[i][j] = -1;
                dist2[i][j] = -1;
            }
        }

        char N[h][w];
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                cin >> N[i][j];
                // 불의 시작 위치
                if (N[i][j] == '*') {
                    dist1[i][j] = 0;
                    Q1.push({i, j});
                }   
                // 사람의 시작 위치
                else if (N[i][j] == '@') {
                    dist2[i][j] = 0;
                    Q2.push({i, j});
                }
            }
        }

        // 불에 대한 BFS
        while(!Q1.empty()) {
            point cur = Q1.front();
            Q1.pop();
            for (int dir=0; dir<4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (nx<0 || nx>=h || ny<0 || ny>=w) continue;
                if (dist1[nx][ny]>=0 || N[nx][ny]=='#') continue;
                dist1[nx][ny] = dist1[cur.x][cur.y] + 1;
                Q1.push({nx, ny});
            }
        }
        
        // 사람에 대한 BFS
        bool enable = false;
		while(!Q2.empty() && !enable) {
            point cur = Q2.front();
            Q2.pop();
            for (int dir=0; dir<4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if (nx<0 || nx>=h || ny<0 || ny>=w) {
                    cout << dist2[cur.x][cur.y] + 1 << '\n'; // 결과 출력
                    enable = true;
                    break;
                }
                if (dist2[nx][ny]>=0 || N[nx][ny]=='#') continue;
                // 불의 이동 시간과 사람의 이동 시간을 비교하여 이동 가능한 경우에만 이동
                if (dist1[nx][ny]>=0 && dist1[nx][ny]<=dist2[cur.x][cur.y]+1) continue;
				dist2[nx][ny] = dist2[cur.x][cur.y] + 1;
                Q2.push({nx, ny});
            }
        }

        if (!enable) {
        	cout << "IMPOSSIBLE" << '\n';
		}
    }

    return 0;
}
